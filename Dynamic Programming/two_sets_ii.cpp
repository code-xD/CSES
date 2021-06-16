#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){
    int n;
    cin>>n;
    int M = 1e9 + 7;
    ll sum = n * (n + 1) / 2;
    if(sum % 2){
        // if total sum is odd then no splits possible.
        cout<<0<<endl;
        return 0;
    }
    sum /= 2;
    vector<vector<ll>> dp(n, vector<ll>(sum + 1));
    // dp[i][j] : to attain j with atmost i elements.
    dp[0][0] = 1;
    for(int i=1; i<n; i++){// looping till n-1 elements because 
    // if we consider n in the set as well then it will lead to double counting.
    // n will always be in the second set.
        for(int j=0; j<= sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j - i >= 0)dp[i][j] = (dp[i-1][j-i] + dp[i][j]) % M;
        }
    }
    cout<<dp[n-1][sum]<<endl;
    return 0;
}