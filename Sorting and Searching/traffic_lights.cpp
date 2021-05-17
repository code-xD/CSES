#include<iostream>
#include<set>

using namespace std;

typedef long long ll;

int main(){
    set<ll> pos;
    int n;
    int k;
    cin>>n>>k;
    pos.insert(n);
    pos.insert(0);
    multiset<ll> dist;
    dist.insert(n);
    while(k--){
        ll loc;
        cin>>loc;
        pos.insert(loc);
        auto itr = pos.find(loc);
        ll low = *prev(itr, 1);
        ll high = *next(itr, 1);
        auto er = dist.find(high - low);
        dist.erase(er);
        dist.insert(high - loc);
        dist.insert(loc - low);
        cout<<*dist.rbegin()<<" ";
    }
    return 0;
}