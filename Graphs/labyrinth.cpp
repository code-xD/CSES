#include <bits/stdc++.h>

using namespace std;

int main(){
	int m, n;
	cin>>n>>m;
	pair<int,int> start, end;
	vector<vector<char>> layout(n, vector<char>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>layout[i][j];
			if(layout[i][j] == 'A')start = make_pair(i, j);
			if(layout[i][j] == 'B')end = make_pair(i,j);
		}
	}
	bool found = false;
	pair<int,int> dir[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	char dirc[] = {'R', 'D', 'U', 'L'};
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	vector<vector<int>> store(n, vector<int>(m));
	queue<pair<int,int>> order;
	order.push(start);
	vis[start.first][start.second] = true;
	while(order.size()){
		pair<int,int> index = order.front();
		order.pop();
		for(int i=0; i<4; i++){
			pair<int,int> curr = make_pair(index.first + dir[i].first, index.second + dir[i].second);
			if(curr.first < 0 || curr.first >= layout.size())continue;
			if(curr.second < 0 || curr.second >= layout[0].size())continue;
			if(layout[curr.first][curr.second] == '#')continue;
			if(vis[curr.first][curr.second])continue;
			vis[curr.first][curr.second] = true;
			order.push(curr);
			store[curr.first][curr.second] = i;
			if(curr == end){
				found = true;
				break;
			}
		}
	}
	if(!found){
		cout<<"NO"<<endl;
		return 0;
	}
	string res = "";
	pair<int,int> index = end;
	while(index != start){
		int i = store[index.first][index.second];
		res.push_back(dirc[i]);
		index = make_pair(index.first - dir[i].first, index.second - dir[i].second);
	}
	cout<<"YES\n"<<res.size()<<endl;
	reverse(res.begin(), res.end());
	cout<<res<<endl;
	return 0;
}