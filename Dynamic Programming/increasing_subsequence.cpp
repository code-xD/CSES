#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int n;
    cin>>n;
    vector<ll> arr;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    vector<ll> seq;
    seq.push_back(arr[0]);
    for(int i=1; i<n; i++){
       if(seq.back() < arr[i])seq.push_back(arr[i]);
       else { // immediate next or the similar element exists.
           int index = lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
           seq[index] = arr[i];
       } 
    }
    cout<<seq.size()<<endl;
    return 0;
}