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
    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            ll ltarget = target - nums[i].first - nums[j].first;
            if (ltarget < 0)
                break;
            int k = j + 1;
            int w = n - 1;
            while (k < w){
                if (nums[w].first + nums[k].first == ltarget){
                    cout << nums[i].second << " " << nums[j].second << " " << nums[k].second << " " << nums[w].second << endl;
                    return 0;
                }
                else if (nums[k].first + nums[w].first < ltarget)
                    k++;
                else
                    w--;
            }
        }
        
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}