#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int total = 0;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr.push_back(num);
        total += num;
    }
    vector<vector<bool>> dp(n+1, vector<bool>(total + 1, false));
    // dp[i][x] = true: if its possible to attain sum x with atmost i coins.
    dp[0][0] = true;
    int possible = 0;
    for(int i=1; i<=n; i++){// atmost i coins.
        for(int tot=0; tot<= total; tot++){
            // either its possible with i-1 coins only.
            if(dp[i-1][tot])dp[i][tot] = dp[i-1][tot];
            // or we need to consider ith coin as well.
            else if(tot >= arr[i-1] && dp[i-1][tot-arr[i-1]])
                dp[i][tot] = dp[i-1][tot - arr[i-1]];
        }
    }
    for(int i=1; i<=total; i++)if(dp[n][i]) possible++;
    cout<<possible<<endl;
    for(int i=1; i<=total; i++){
        for(int j=1; j<=n; j++){
            if(dp[j][i]){
                cout<<i<<" ";
                break;
            }
        }
    }
    return 0;
}