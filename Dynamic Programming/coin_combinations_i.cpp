#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n;
    ll x;
    cin>>n>>x;
    vector<ll> dp(x+1, 0);
    vector<ll> arr;
    ll M = 1e9 + 7;
    dp[0] = 1;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(i - arr[j] >= 0)dp[i] = (dp[i - arr[j]] + dp[i]) % M;
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}