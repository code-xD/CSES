#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
typedef long long ll;

int main(){
    int n;
    ll target;
    cin>>n>>target;
    vector<pair<ll,int>> arr;
    for(int i=0;i<n; i++){
        ll num = 0;
        cin>>num;
        arr.push_back(make_pair(num, i));
    }
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = arr.size() - 1;
    while(i<j){
        if(arr[i].first + arr[j].first == target){
            cout<<arr[i].second + 1<<" "<<arr[j].second + 1<<endl;
            target = 0;
            break;
        }
        else if(arr[i].first + arr[j].first < target) i++;
        else j--;
    }
    if (target)
        cout <<"IMPOSSIBLE"<<endl;
    return 0;
}