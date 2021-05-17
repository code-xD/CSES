#include<iostream>
#include<set>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    multiset<ll> stacks;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        if(stacks.upper_bound(num) == stacks.end()){
            stacks.insert(num);
        }
        else{
            stacks.erase(stacks.upper_bound(num));
            stacks.insert(num);
        }
    }
    cout<<stacks.size()<<endl;
    return 0;
}