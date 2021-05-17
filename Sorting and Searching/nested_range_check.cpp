#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
typedef long long ll;

typedef struct Range{
    int id;
    ll low;
    ll high;
}range;

bool sortByInWard(const range &a, const range &b){
    if(a.low != b.low)return a.low < b.low;
    return a.high > b.high;
}

int main(){
    vector<range> ranges;
    vector<range> track;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        ll a, b;
        cin>>a>>b;
        ranges.push_back({i, a, b});
    }
    sort(ranges.begin(), ranges.end(), sortByInWard);
    vector<int> ans1(n, 0);
    vector<int> ans2(n, 0);
    ll maxR = 0;
    for(int i=0; i<n; i++){
        if(ranges[i].high <= maxR)ans2[ranges[i].id] = 1;
        maxR = max(ranges[i].high, maxR);
    }
    ll minR = ranges[n-1].high;
    for (int i = n - 2; i >= 0; i--){
        if (ranges[i].high >= minR)
            ans1[ranges[i].id] = 1;
        minR = min(ranges[i].high, minR);
    }
    for(auto a: ans1)cout<<a<<" ";
    cout<<endl;
    for(auto a: ans2)cout<<a<<" ";
    cout<<endl;
    return 0;
}