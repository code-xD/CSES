#include<iostream>
#include<vector>
#include<climits>

using namespace std;
typedef long long ll;

ll totProduct(vector<ll>& time_taken, ll time){
    ll ans = 0;
    for(int i=0; i<time_taken.size(); i++)ans += time / time_taken[i];
    return ans;
}

ll minTime(vector<ll> &time_taken, ll t, ll right){
    ll left = 1;
    ll mid = 0;
    ll ans = 0;
    while(left<=right){
        mid = left + (right - left) / 2;
        if(totProduct(time_taken, mid) < t)left = mid + 1;
        else if(totProduct(time_taken, mid) >= t){
            ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}

// Aggressive Cow
int main(){
    int n;
    cin>>n;
    ll t;
    cin>>t;
    ll minval = LONG_LONG_MAX;
    vector<ll> time_taken;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        minval = min(minval, num);
        time_taken.push_back(num);
    }
    ll right = minval*t;
    cout<<minTime(time_taken, t, right)<<endl;
    return 0;
}