#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> arr;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    map<ll,int> freq;
    int i=0;
    int j=0;
    freq[arr[j]]++;
    ll ans = 0;
    while(j<n){
        if(freq.size() <= k){
            j++;
            if(j<n)freq[arr[j]]++; 
        }
        else if(freq.size() > k){
            ans += j - i;
            freq[arr[i]]--;
            if(freq[arr[i]] == 0)freq.erase(arr[i]);
            i++;
        }
    }
    // Since j=n only when <=k criteria is met we only need to calculate the subarrays possible ending at j-1.
    while(i<j){
        ans += j - i;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}
