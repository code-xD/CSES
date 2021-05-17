#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int n;
    ll target;
    cin>>n>>target;
    vector<pair<ll, int>> nums;
    for(int i=0; i<n; i++){
        ll num;
        cin>>num;
        nums.push_back(make_pair(num, i + 1));
    }
    sort(nums.begin(), nums.end());
    for(int i=0; i<n-2; i++){
        ll ltarget = target - nums[i].first;
        if(ltarget < 0)break;
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            if(nums[j].first + nums[k].first == ltarget){
                cout<<nums[i].second<<" "<<nums[j].second<<" "<<nums[k].second<<endl;
                return 0;
            }
            else if(nums[j].first + nums[k].first < ltarget)j++;
            else k--;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}