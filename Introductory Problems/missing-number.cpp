#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	ll n;
	cin>>n;
	ll total = (n*(n+1))/2;
    ll sum = 0;
    n--;
    while(n--){
        ll val = 0;
        cin>>val;
        sum += val;
    }
    cout<<total - sum<<endl;
	return 0;
}