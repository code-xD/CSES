#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct range{
    int id;
    ll arr;
    ll dept;

    friend bool operator<(const struct range &a, const struct range &b){
        if(a.arr != b.arr)return a.arr < b.arr;
        return a.dept < b.dept;
    }
    
}range;

typedef struct room{
    int id;
    ll dept;
    int key;

    friend bool operator<(const struct room &a, const struct room &b){
        if(a.dept == b.dept)return a.id < b.id;
        return a.dept < b.dept;
    }

}room;

int main(){
    int n;
    cin>>n;
    vector<range> slots;
    for(int i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        slots.push_back({i, a, b});
    }
    sort(slots.begin(), slots.end());
    set<room> alloted;
    vector<int> ans(n,0);
    queue<int> keys;
    int max_key = 0;
    for(int i=0; i<n; i++){
        int key;
        if(alloted.empty() && keys.empty())key = ++max_key;
        else if (alloted.empty() && keys.size()){
            key = keys.front();
            keys.pop();
        }
        else{
            while(alloted.size() && alloted.begin()->dept < slots[i].arr){
                keys.push(alloted.begin()->key);
                alloted.erase(alloted.begin());
            }
            if(keys.size()){
                key = keys.front();
                keys.pop();
            }
            else key = ++max_key;
            
        }
        alloted.insert({slots[i].id, slots[i].dept, key});
        ans[slots[i].id] = key;
    }
    cout<<max_key<<endl;
    for(int i=0; i<n; i++)cout<<ans[i]<<" ";
    return 0;
}