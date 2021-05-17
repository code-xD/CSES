#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// monotonic stack;


int main(){
    int n;
    cin>>n;
    vector<ll> arr;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    stack<pair<ll, int>> mono;
    vector<int> ans;
    for(int i=0; i<n; i++){
        while(mono.size() && mono.top().first >= arr[i])mono.pop();
        if(mono.empty())ans.push_back(0);
        else ans.push_back(mono.top().second);
        mono.push({arr[i], i + 1});
    }
    for(int i=0; i<n; i++)cout<<ans[i]<<" ";
    return 0;
}