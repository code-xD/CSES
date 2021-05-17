#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long n;
	cin>>n;
	cout<<n<<" ";
	while(n!=1){
		if(n%2)n = 3*n + 1;
		else n /= 2;
		cout<<n<<" ";
	}
	return 0;
}
