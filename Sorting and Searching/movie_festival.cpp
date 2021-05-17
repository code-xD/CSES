#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

bool compbysec(const pair<int,int> &a, const pair<int,int> &b){
    return a.second < b.second;
}

int main(){
    vector<pair<ll,ll>> movies;
    int n;
    cin>>n;
    while(n--){
        ll start, end;
        cin>>start>>end;
        movies.push_back(make_pair(start, end));
    }
    sort(movies.begin(), movies.end(), compbysec);
    int count = 0;
    ll end = 0;
    for(int i=0; i < movies.size(); i++){
        if(movies[i].first >= end){
            count++;
            end = movies[i].second;
        }
    }
    cout<<count<<endl;
}
