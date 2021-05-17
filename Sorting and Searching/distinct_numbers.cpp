#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int distinct = 1;
    for(int i=1; i<arr.size(); i++)if(arr[i] != arr[i-1])distinct++;
    cout<<distinct<<endl;
    return 0;
}