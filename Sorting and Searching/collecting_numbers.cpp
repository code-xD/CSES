#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr[num - 1] = i;
    }
    int ans = 1;
    for(int i = 1; i<n ; i++){
        if(arr[i - 1] > arr[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}