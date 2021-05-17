#include<iostream>
using namespace std;

int main(){
    unsigned long long n;
    cin>>n;
    int ans = 0;
    unsigned long long five = 5;
    while(n / five){
        ans += n/five;
        five *= 5;
    }
    cout<<ans;
    return 0;
}