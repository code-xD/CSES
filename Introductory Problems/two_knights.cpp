#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(unsigned long long i=1; i<=t; i++){
        if(i==1)cout<<0<<endl;
        else cout<<( i*i*(i*i - 1)/2 - 4*(i-1)*(i-2) )<<endl;     }   
    return 0;
}