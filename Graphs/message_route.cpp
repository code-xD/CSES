#include<bits/stdc++.h>
using namespace std;
// Use BFS(Because Unweighted Graph)
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n, vector<int>());
    for(int i=0; i<m; i++){
        int to, from;
        cin>>from>>to;
        to--; from--;
        adj[to].push_back(from);
        adj[from].push_back(to);
    }
    vector<bool> vis(n, false);
    vector<int> p(n ,-1);
    vector<int> d(n, 0);
    queue<int> order;
    order.push(0);
    vis[0] = true;
    while(order.size()){
        int node = order.front(); order.pop();
        for(auto c: adj[node]){
            if(vis[c])continue;
            p[c] = node;
            d[c] = d[node] + 1;
            order.push(c);
            vis[c] = true;
        }
    }
    if(d[n-1] == 0)cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int> path;
        cout<<d[n-1] + 1<<endl;
        int index = n - 1;
        while(index != -1){
            path.push_back(index + 1);
            index = p[index];
        }
        reverse(path.begin(), path.end());
        for(auto dir: path){
            cout<<dir<<" ";
        }
    }
    return 0;
}