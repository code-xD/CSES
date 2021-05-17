#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int n;
    ll target;
    cin>>n>>target;
    vector<ll> arr;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    int i = 0;
    int j = 0;
    ll rsum = arr[0];
    int ans = 0;
    while(j < n){
        if(rsum == target){
            ans++;
            j++;
            if (j < n)
                rsum += arr[j];
            else
                break;
        }
        else if (i < j && rsum > target){
            rsum -= arr[i];
            i++;
        }
        else if (i <= j && rsum < target){
            j++;
            if (j < n)
                rsum += arr[j];
            else break;
        }
        else if (i == j && rsum > target){
            rsum -= arr[i];
            i++;
            j++;
            if (j < n) rsum += arr[j];
            else break;
        }
    }
    cout<<ans<<endl;
    return 0;
}