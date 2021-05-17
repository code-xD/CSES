#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;

int result = 0;

bool valid_pos(vector<pair<int,int>> &pos, vector<vector<int>> &board, int i, int j){
    if(board[i][j] != 0)return false;
    for(auto p: pos){
        if(abs(p.first - i) == abs(p.second - j))return false;
        else if(p.first == i || p.second == j)return false;
    }
    return true;
}

void backtrack(vector<pair<int,int>> pos, vector<vector<int>> board){ 
    if(pos.size() == 8){
        result++;
        return;
    }
    int i = pos.size();
    for(int j=0; j<8; j++){
        if(valid_pos(pos, board, i, j)){
            pos.push_back(make_pair(i, j));
            board[i][j] = 1;
            backtrack(pos, board);
            board[i][j] = 0;
            pos.pop_back();
        }
    }

}


int main(){
    vector<vector<int>> board(8, vector<int>(8, 0));
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            char val;
            cin>>val;
            if(val == '*')board[i][j] = -1;
        }
    }
    vector<pair<int,int>> pos;
    backtrack(pos, board);
    cout<<result<<endl;
    return 0;
}