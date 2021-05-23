#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int x;
    cin>>n>>x;
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    vector<int> arr;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    int M = 1e9 + 7;
    dp[0][0] = 1;
    // dp[i][j] -> i: atmost first i coins can be used.
    // j : target sum we want to achieve.
    // dp[i][j] = dp[i][j - arr[j]] + dp[i-1][j]; 
    // Either we consider the jth coin in the combination or we don't.
    for(int i=1; i<=n; i++){
        for(int j=0; j<=x; j++){
            dp[i][j] = dp[i-1][j]; // Total combination of target without the ith coin.
            if(j - arr[i-1] >= 0)
                dp[i][j] = (dp[i][j - arr[i-1]] + dp[i][j]) % M; // The array of coins is zero indexed. 
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}