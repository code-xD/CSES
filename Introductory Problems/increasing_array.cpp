#include<iostream>
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin>>n;
    ll max_no = 0, ans = 0;
    while(n--){
        ll num;
        cin>>num;
        if(num > max_no)max_no = num;
        else ans += max_no - num;
    }
    cout<<ans<<endl;
    return 0;
}