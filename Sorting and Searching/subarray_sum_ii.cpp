#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n;
    ll target;
    cin>>n>>target;
    vector<ll> arr;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    map<ll, int> prefix_sum;
    prefix_sum[0]++;
    ll rsum = 0;
    ll ans = 0;
    for(int i=0; i<n; i++){
        rsum += arr[i];
        ans += prefix_sum[rsum - target];
        prefix_sum[rsum]++;
    }
    cout<<ans<<endl;
    return 0;
}