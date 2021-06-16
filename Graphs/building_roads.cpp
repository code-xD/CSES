#include<bits/stdc++.h>
using namespace std;

void dfs(vector<bool>& vis, vector<vector<int>>& adj, int i){
    if(vis[i])return;
    vis[i] = true;
    for(int c: adj[i]){
        dfs(vis, adj, c);
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<bool> vis(n);
    vector<vector<int>> adj(n, vector<int>());
    for(int i=0; i<m; i++){
        int s,e;
        cin>>s>>e;
        s--; e--;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    vector<int> base;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            base.push_back(i);
            dfs(vis, adj, i);
        }
    }
    cout<<base.size() - 1<<endl;
    for(int i=0; i<base.size()-1; i++){
        cout<<base[i] + 1<<" "<<base[i+1] + 1<<endl;
    }
}