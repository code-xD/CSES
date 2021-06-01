#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, INT_MAX));
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b ; j++){
            // if we already have a square then the moves required is zero.
            if(i==j){
                dp[i][j] = 0;
                continue;
            }
            // cut at a random valid line and find the minimum moves to cut the remnant rect
            // this top down approach is repeated for all valid k.
            for(int k=1; k<max(i,j); k++){
                if(j > k)dp[i][j] = min(1 + dp[i][j-k] + dp[i][k], dp[i][j]);
                if(i > k)dp[i][j] = min(1 + dp[i-k][j] + dp[k][j], dp[i][j]); 
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}