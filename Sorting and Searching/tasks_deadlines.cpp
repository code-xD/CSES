#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    vector<pair<ll,ll>> tasks;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        tasks.push_back(make_pair(a,b));
    }
    sort(tasks.begin(), tasks.end());
    ll ans = 0;
    ll curr_time = 0;
    for(int i=0; i<n; i++){
        curr_time += tasks[i].first;
        ans += tasks[i].second - curr_time;
    }
    cout<<ans<<endl;
    return 0;
}