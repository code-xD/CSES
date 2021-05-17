#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t = 0;
    cin>>t;
    cout<<(unsigned long long) pow(2, t) % (long) (1e9 +7);
    return 0;
}