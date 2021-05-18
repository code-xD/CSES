#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
// Aggressive Cow Problem.

bool isValid(vector<ll> &arr, ll max_sum, int limit){
    ll lsum = 0;
    int count = 1; // Since max_sum >= largest_element of the array we need to have count = 1. Else the final count will always have one less count.
    for(int i=0; i<arr.size(); i++){
        lsum += arr[i];
        if(lsum > max_sum){
            count++;
            lsum = arr[i];
        }
    }
    if(count > limit)return false;
    return true;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> arr;
    ll start = 0, end = 0;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
        end += num;
        start = max(start, num);
    }
    ll res = 0;
    while(start <= end){
        ll mid = start + (end - start)/2;
        if(isValid(arr, mid, k)){
            res = mid;
            end = mid - 1;
        }
        else start = mid + 1;
    }
    cout<<res<<endl;
    return 0;
}