#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<pair<ll, int>> logs;
    while(n--){
        ll low, high;
        cin>>low>>high;
        logs.push_back(make_pair(low, 0));
        logs.push_back(make_pair(high, 1));
    }
    sort(logs.begin(), logs.end());
    ll ans = 0;
    ll max_ans = 0;
    for(auto log: logs){
        if(log.second)ans -= 1;
        else ans += 1;
        max_ans = max(ans, max_ans);
    }
    cout<<max_ans<<endl;
    return 0;
}