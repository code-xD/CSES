#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

int main(){
    // prob statement can be treated as: max(|x1 - c| + |x2 - c| + |x3 -c| + ... + |xn - c|), find c. In this case c will be median. 
    int n;
    cin>>n;
    vector<ll> arr;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    ll median = 0;
    if(arr.size() % 2) median = arr[arr.size() / 2];
    else median = (arr[arr.size() / 2]  + arr[(arr.size() - 1)/ 2]) / 2;
    ll ans = 0;
    for(int i=0; i<n; i++)
        ans += abs(arr[i] - median);
    cout<<ans<<endl;
    return 0;
}