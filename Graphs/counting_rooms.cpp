#include<bits/stdc++.h>
using namespace std;
//counting rooms

void visited(int i, int j, vector<vector<char>> &layout){
    if(i>=0 && i < layout.size() && j <layout[0].size() && j>=0);
    else return;
    if(layout[i][j] == '#') return;
    layout[i][j] = '#';
    visited(i+1, j, layout);
    visited(i, j+1, layout);
    visited(i-1, j, layout);
    visited(i, j-1, layout);
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<char>> layout(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char data;
            cin>>data;
            layout[i][j] = data;
        }
    }
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(layout[i][j] == '.'){
                res++;
                visited(i, j, layout);
            }
        }
    }
    cout<<res<<endl;
    return 0;
} 