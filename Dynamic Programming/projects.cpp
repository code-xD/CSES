#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

typedef struct project{
    ll sdate;
    ll edate;
    ll prize;
}project;

bool cmpProjects(project p1, project p2){
    // if two projects end on the same day then pick the one with higher prize first.
    if(p1.edate == p2.edate)return p1.prize > p2.prize;
    return p1.edate < p2.edate;
}

int main(){
    int n;
    cin>>n;
    vector<project> projects;
    for(int i=0; i<n; i++){
        ll start;
        ll end;
        ll prize;
        cin>>start>>end>>prize;
        projects.push_back({start, end, prize});
    }
    sort(projects.begin(), projects.end(), cmpProjects);
    vector<ll> dp(n + 1);
    // create a set of projects with their end date.
    set<pair<ll, int>> project_index;
    project_index.insert(make_pair(0, 0));
    for(int i=1; i<=projects.size(); i++){
        project_index.insert(make_pair(projects[i-1].edate, i));
    }
    // dp[i] :- max amount earned on ith day.
    // Since we can't accomodate 10^9 days and need to decide at the end date of each project.
    // We go with i representing the end date of ith project in ascending order of end date.
    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1];
        // find the last project which can be done before ith project begins.
        auto it = project_index.lower_bound(make_pair(projects[i-1].sdate-1, 0));
        if(it != project_index.begin() && projects[i-1].sdate -1 != projects[it->second - 1].edate)it--;
        // if it is possible that the amount maximises considering the ith project then override
        // the amount earned by atmost ith project.
        dp[i] = max(dp[i], dp[it->second] + projects[i-1].prize);
    }
    cout<<dp[n]<<endl;
    return 0;
}