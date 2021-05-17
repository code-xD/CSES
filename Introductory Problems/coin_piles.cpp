#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        unsigned long long n1, n2;
        cin>>n2>>n1;
        if((4 * n1 - 2 * n2) >= 0 && (4 * n1 - 2 * n2) % 6 == 0 && (4 * n2 - 2 * n1) >= 0 && (4 * n2 - 2 * n1) % 6 == 0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}