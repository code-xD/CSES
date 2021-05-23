#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    arr.push_back(0);
    for(int i=1; i<=n; i++){
        int num = i;
        int min_steps = INT_MAX;
        while(num!=0){
            if(num % 10)min_steps = min(arr[i - num % 10] + 1, min_steps);
            num /= 10;
        }
        arr.push_back(min_steps);
    }
    cout<<arr[n]<<endl;
    return 0;
}