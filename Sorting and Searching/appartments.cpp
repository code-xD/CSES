#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

int bsearch(vector<ll>& apt, int left, ll find, int k){
    int right = apt.size() - 1;
    int ans = -1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(apt[mid] >= find - k && apt[mid] <= find + k){
            ans = mid;
            right = mid - 1;
        }
        else if(apt[mid] < find - k)left = mid + 1;
        else right = mid - 1;
    }
    return ans;
}


int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll> req;
    vector<ll> apt;
    for(int i=0; i<n; i++){
        ll inp;
        cin>>inp;
        req.push_back(inp);
    }
    for(int i=0; i<m; i++){
        ll inp;
        cin>>inp;
        apt.push_back(inp);
    }
    sort(req.begin(), req.end());
    sort(apt.begin(), apt.end());
    int ans = 0;
    int lb = 0;
    for(int i=0; i<req.size(); i++){
        int ret = bsearch(apt, lb, req[i], k);
        if(ret!=-1){
            lb = ret + 1;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}