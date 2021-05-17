#include<iostream>
#include<string>
using namespace std;
typedef unsigned long long ull;

ull pow(ull a, ull b){
    ull ret = 1;
    while(b--)ret *=a;
    return ret;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ull val = 0;
        ull num;
        cin>>num;
        int i = 0;
        while(num > 0){
            i++;
            val = 9 * i * pow(10, i-1); 
            if(num > val)num -= val;
            else break;
        }
        if(i==1)cout<<num<<endl;
        else{
            num--;
            ull digit = num / i;
            cout<<to_string(pow(10, i - 1) + digit)[num % i]<<endl; 
        }
    }
    return 0;
}
