#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main(){
    ll M = 1e9 + 7;
    int n, m;
    cin>>n>>m;
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    // dp(i, x) = total combination of valid arrays of size i and ending at x.
 
    vector<int> arr;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<=m; j++){
            ll comb = 0;
            // if the value of the array at index is fixed
            // then other combination is not valid hence zero.
            if(arr[i] != 0 && arr[i]!=j)dp[i][j-1] = 0;
            else if(i==0)dp[i][j-1] = 1;
            else{
                for(int k = -1; k<=1; k++){
                    if(j + k > 0 && j + k <=m)comb = (comb + dp[i-1][j+k-1]) % M;
                }
                dp[i][j-1] = comb;
            }
        }
    }
    ll ans = 0;
    for(int i=0; i<m; i++)ans = (ans + dp[n-1][i]) % M;// get the sum of all possible
    // valid combination at the end of array.
    cout<<ans<<endl;
    return 0;
}