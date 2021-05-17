#include<iostream>
#include<vector>
#include<set>

using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin>>n>>m;
    multiset<ll, greater<ll>> tickets;
    for(int i=0; i<n; i++){
        ll ticket;
        cin>>ticket;
        tickets.insert(ticket);
    }
    for(int i=0; i<m; i++){
        ll limit;
        cin>>limit;
        multiset<ll, greater<ll>>::iterator find = tickets.lower_bound(limit);
        if(find!=tickets.end()){
            cout << *find << endl;
            tickets.erase(find);
        }
        else cout<<-1<<endl;
    }
    return 0;
}