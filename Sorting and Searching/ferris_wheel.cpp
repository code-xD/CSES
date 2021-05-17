#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

int main(){
    int n;
    ll limit;
    cin>>n>>limit;
    vector<int> weights;
    for(int i=0; i<n; i++){
        ll w;
        cin>>w;
        weights.push_back(w);
    }
    sort(weights.begin(), weights.end());
    int i=0;
    int j=weights.size() - 1;
    int ans = 0;
    while(i<j){
        if(weights[i] + weights[j] <= limit){
            ans++;
            i++;
            j--;
        }
        else {
            ans++;
            j--;
        }
    }
    if(j==i && weights[j] <= limit)ans++;
    cout<<ans<<endl;
    return 0;
}