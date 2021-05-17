#include <iostream>
using namespace std;

int main(){
    unsigned long long n;
    cin>>n;
    if(n*(n+1) % 4 != 0)cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        unsigned long long tot = n * (n + 1) / 4;
        unsigned long long i,j;
        
        if(tot % n == 0){
            cout<<(2 * (tot / n - 1) + 1)<<endl;
            i = n-1;
            j = 1;
            cout<<n<<" ";
            tot -= n;
            
        }
        else{
            cout<<(2 * tot / (n + 1))<<endl;
            i = n;
            j = 1;
        }
        while(tot != 0){
            cout<<i<<" "<<j<<" ";
            tot -= (i+j);
            i--;
            j++;
            
        }
        tot = n * (n + 1) / 4;
        if(tot % n == 0)cout<<endl<<(n - 2 * (tot / n - 1) - 1)<<endl;
        else cout<<endl<<(n - 2 * tot / (n + 1))<<endl;
        while(i>=j){
            cout<<i<<" "<<j<<" ";
            i--;
            j++;
        }
        cout<<endl; 
    }
    return 0;
}