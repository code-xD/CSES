#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n;
    ll x;
    cin>>n>>x;
    vector<ll> arr;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    vector<ll> dp(x+1, -1);
    dp[0] = 0;
    for(int i=1; i<=x; i++){
        vector<ll> coins;
        for(int j=0; j<n; j++){
            if(i - arr[j] >=0 && dp[i - arr[j]] != -1)coins.push_back(dp[i-arr[j]]);
        }
        if(coins.size())dp[i] = LONG_MAX;
        for(int j=0; j<coins.size(); j++)dp[i] = min(dp[i], coins[j] + 1);
    }
    cout<<dp[x]<<endl;
    return 0;
}