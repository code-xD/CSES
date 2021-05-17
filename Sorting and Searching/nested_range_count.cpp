#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

typedef struct range{
    ll left;
    ll right;
    ll id;
} range;

bool sortByInWard(const range &a, const range &b){
    if (a.left != b.left)
        return a.left < b.left;
    return a.right > b.right;
}

typedef tree<pair<ll, ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(){
    int n;
    cin>>n;
    vector<range> ranges;
    indexed_set ind1, ind2;
    for(int i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        ranges.push_back({a, b, i});
    }
    sort(ranges.begin(), ranges.end(), sortByInWard);
    vector<int> ans1(n, 0);
    vector<int> ans2(n, 0);
    for(int i=0; i<ranges.size(); i++){
        ind1.insert(make_pair(ranges[i].right, -i));
        ans2[ranges[i].id] = i - ind1.order_of_key(make_pair(ranges[i].right, -i));
    }
    for(int i=n-1; i>=0; i--){
        ind2.insert(make_pair(ranges[i].right, -i));
        ans1[ranges[i].id] = ind2.order_of_key(make_pair(ranges[i].right, -i));
    }

    for(int i=0; i<ranges.size(); i++)cout<<ans1[i]<<" ";
    cout<<endl;
    for(int i=0; i<ranges.size(); i++)cout<<ans2[i]<<" ";
    return 0;
}