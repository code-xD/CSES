#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main(){
    int n;
    cin>>n;
    vector<vector<bool>> grid(n, vector<bool>(n, false));
    vector<vector<ll>> dp(n, vector<ll>(n));
    int M = 1e9 + 7;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char ch;
            cin>>ch;
            if(ch=='*')grid[i][j] = true;
        }
    }
    if(!grid[n-1][n-1])dp[n-1][n-1] = 1;
    for(int i=n-2; i>=0; i--){
        if(!grid[i][n-1])dp[i][n-1] = dp[i+1][n-1];
        if(!grid[n-1][i])dp[n-1][i] = dp[n-1][i+1];
    }
    for(int i=n-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            if(!grid[i][j])
            dp[i][j] = (dp[i+1][j] +  dp[i][j+1]) % M; 
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}