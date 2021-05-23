#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n;
    cin>>n;
    vector<ll> dp(n+1);
    dp[0] = 1;
    ll M = 1e9 + 7;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            if(i-j >= 0)dp[i] = (dp[i] + dp[i-j]) % M;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}