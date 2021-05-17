#include<iostream>
#include<vector>
#include<set>

using namespace std;
typedef long long ll;

int main(){
    set<ll> bst;
    vector<ll> arr;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }

    int ans = 0;
    int curr = 0;
    for(int i=0; i<n; i++){
        while(bst.find(arr[i]) != bst.end()){
            bst.erase(bst.find(arr[curr]));
            curr++;
        }
        bst.insert(arr[i]);
        ans = max(int(bst.size()), ans);
    }
    cout<<ans<<endl;
    return 0;
}