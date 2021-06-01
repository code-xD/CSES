#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n;
    cin>>n;
    vector<ll> arr;
    ll tot = 0;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        tot += num;
        arr.push_back(num);
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int l = n-1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) dp[l][r] = arr[l];
            else dp[l][r] = max(arr[l]-dp[l+1][r], arr[r]-dp[l][r-1]); 
        }
    }
    // final val = [ total sum ( arr[0]  + arr[1] + ...) - difference( arr[i1] - arr[i2] + arr[i3]) ]/ 2 
    cout<<(tot + dp[0][n-1])/2<<endl;
    return 0;
}