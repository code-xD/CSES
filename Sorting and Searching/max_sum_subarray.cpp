#include<iostream>
#include<vector>
#include<climits>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<ll> arr;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    ll ans = LLONG_MIN;
    ll csum = 0;
    for(int i=0; i<n; i++){
        csum = max(csum + arr[i], arr[i]);
        ans = max(ans,csum);
    }
    cout<<ans<<endl;
    return 0;
}