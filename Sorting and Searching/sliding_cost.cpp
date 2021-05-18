#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to adjust two sets such that median is always last element of lset and (first element of rset(if even))
void insert_running_median(ll &left_sum, ll &right_sum, multiset<ll> &lset, multiset<ll> &rset, vector<ll> &arr, int k, int i){
    if (lset.size() < (k + 1) / 2){
        lset.insert(arr[i]);
        left_sum += arr[i];
    }
    else if (*lset.rbegin() > arr[i]){
        ll ins = *lset.rbegin();
        lset.erase(prev(lset.end(), 1));
        lset.insert(arr[i]);
        left_sum += (arr[i] - ins);
        rset.insert(ins);
        right_sum += ins;
    }
    else{
        rset.insert(arr[i]);
        right_sum += arr[i];
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<ll> arr;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        arr.push_back(num);
    }
    multiset<ll> lset;
    multiset<ll> rset;
    
    ll lsum = 0;
    ll rsum = 0;

    for(int i=0; i<k; i++){
        insert_running_median(lsum, rsum, lset, rset, arr, k, i);
    }
    
    ll curr_median = 0;

    // cost = lset.size() * median - lsum + rsum - rset.size() * median; 
    // because all the lset will be less than median and all the rset will be greater than median.
    if (k % 2) curr_median = *lset.rbegin();
    else curr_median = (*lset.rbegin() + *rset.begin() ) / 2;
    ll loc_cost = lset.size() * curr_median - lsum + rsum - rset.size() * curr_median;

    for(int i=k; i<n; i++){
        cout<<loc_cost<<" ";
        if(lset.find(arr[i-k]) != lset.end()){
            lset.erase(lset.find(arr[i-k]));
            if(k!=1){
                lset.insert(*rset.begin());
                lsum += (*rset.begin() - arr[i - k]);
                rsum -= *rset.begin();
                rset.erase(rset.begin());
            }
            else lsum -= arr[i-k];
        }
        else{
            rset.erase(rset.find(arr[i-k]));
            rsum -= arr[i-k];
        }
        insert_running_median(lsum, rsum, lset, rset, arr, k, i);
        if (k % 2)
            curr_median = *lset.rbegin();
        else
            curr_median = (*lset.rbegin() + *rset.begin()) / 2;
        loc_cost = lset.size() * curr_median - lsum + rsum - rset.size() * curr_median;
    }
    cout << loc_cost << endl;
    return 0;
}