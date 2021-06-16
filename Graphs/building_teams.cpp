#include<bits/stdc++.h>
using namespace std;
// 2 coloring

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n, vector<int>());
    for(int i=0; i<m; i++){
        int to, fr;
        cin>>to>>fr;
        to--;fr--;
        adj[to].push_back(fr);
        adj[fr].push_back(to);
    }
    int clr = 1;
    vector<bool> vis(n, false);
    vector<int> color(n, 0);
    queue<int> order;
    for(int i=0 ;i<n; i++){
        // visited is true only if element is pushed to queue
        // and has been assigned a color.
        if(vis[i])continue;
        order.push(i);
        vis[i] = true;
        color[i] = clr;
        while(order.size()){
            vector<int> save;
            while(order.size()){
                for(auto c: adj[order.front()]){
                    // if parent color == child color then graph is not bipartite.
                    if(color[c] == clr){
                        cout<<"IMPOSSIBLE"<<endl;
                        return 0;
                    }
                    if(vis[c])continue;
                    save.push_back(c);
                    vis[c] = true;
                    color[c] = (clr == 1) ? 2 : 1;
                }
                order.pop();
            }
            for(auto c: save)order.push(c);
            // change the parent color if all the elements of queue are emptied.
            clr = (clr == 1) ? 2 : 1;
        }
    }
    
    for(int i=0; i<n; i++)cout<<color[i]<<" ";
}