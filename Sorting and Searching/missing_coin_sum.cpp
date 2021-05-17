#include<iostream>
#include<vector>
#include<algorithm>

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
    sort(arr.begin(), arr.end());
    ll ans = 1;
    for(int i=0; i<n; i++){
        if(ans < arr[i])break;
        else ans += arr[i];
    }
    cout<<ans<<endl;
    return 0;
}