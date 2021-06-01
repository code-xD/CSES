#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    vector<int> tests;
    cin>>t;
    int N = 0;
    for(int i=0; i<t; i++){
        int test;
        cin>>test;
        tests.push_back(test);
        N = max(test, N);
    }
    int M = 1e9 + 7;
    vector<vector<int>> dp(N, vector<int>(8));
    vector<vector<int>> conn = {
        {0, 2, 3, 4, 6},
        {1,5,7},
        {0,2,3,4,6},
        {1,5,7},
        {0,2,3,4,6},
        {0,2,3,4,6},
        {0,2,3,4,6},
        {1,5,7}}; // defines the allowed next tracks.
    // Implement previous combinatrics.
    for(int i=0; i<N; i++){
        for(int j=0; j<8; j++){
            if(i==0)dp[i][j] = 1;
            else{
                for(int c: conn[j])dp[i][c] = (dp[i][c] + dp[i-1][j]) % M;
            }
        }
    }
    for(int i=0; i<tests.size(); i++){
        int n = tests[i] - 1;
        int ans = (dp[n][1] + dp[n][3]) % M;
        cout<<ans<<endl;
    }
}