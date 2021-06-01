#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1, str2;
    cin>>str1>>str2;
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
    for(int i=0; i<=str1.size(); i++){
        for(int j=0; j<=str2.size(); j++){
            if(i==0 && j==0)continue;
            else if(i==0)dp[i][j] = dp[i][j-1] + 1;
            else if(j==0)dp[i][j] = dp[i-1][j] + 1;
            else{
                if(str1[i-1] == str2[j-1])dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
        }
    }
    cout<<dp[str1.size()][str2.size()]<<endl;
    return 0;
}