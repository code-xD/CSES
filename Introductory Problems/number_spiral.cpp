#include<iostream>
using namespace std;
typedef unsigned long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        long y,x;
        cin>>y>>x;
        long mVal = max(y, x);
        ll ans = 0;
        if(mVal % 2 == 0)ans = mVal * mVal - x + 1 - mVal + y;
        else ans = mVal * mVal - y + 1 - mVal + x;
        cout<<ans<<endl;
    }
    return 0;
}