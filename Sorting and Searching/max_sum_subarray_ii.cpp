#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n, a, b;
    cin>>n>>a>>b;
    vector<ll> prefix_sum = {0};
    multiset<ll> prefix;
    ll tot_sum = 0;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        tot_sum += num;
        prefix_sum.push_back(tot_sum);
    }
    ll ans = LONG_LONG_MIN;
    for(int i=a; i<=n; i++){
        prefix.insert(prefix_sum[i-a]);
        if(i - b > 0)prefix.erase(prefix.find(prefix_sum[i-b-1]));
        ans = max(ans, prefix_sum[i] - *prefix.begin());
    }
    cout<<ans<<endl;
    return 0;
}