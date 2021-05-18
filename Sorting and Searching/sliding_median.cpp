#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
typedef tree<pair<ll,int>, null_type, less<pair<ll,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> arr;
     
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    indexed_set median;
    for(int i=0; i<k-1; i++){
        median.insert(make_pair(arr[i], i));
    }
    for(int i=k-1; i<n; i++){
        median.insert(make_pair(arr[i], i));
        if(i - k >= 0)median.erase(median.find(make_pair(arr[i-k], i-k)));
        if(k%2)cout<<median.find_by_order(k/2)->first<<" ";
        else cout << median.find_by_order(k/2 - 1)->first << " ";
    }
    return 0;
}