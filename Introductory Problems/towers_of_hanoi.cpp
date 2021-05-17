#include<iostream>
#include<cmath>

using namespace std;

void solve(int n, int src, int dest, int med){
    if(n==0)return;
    if(n==1){
        cout<<src<<" "<<dest<<endl;
        return;
    }
    // Step 1: Move n-1 blocks from source to spare using dest
    // Step 2: Move biggest block from source to dest
    // Step 3: Move n-1 blocks from dest to source using spare
    solve(n-1, src, med, dest);
    cout<<src<<" "<<dest<<endl;
    solve(n-1, med, dest, src);
}

int main(){
    unsigned long long n;
    cin>>n;
    cout<<(pow(2,n) - 1)<<endl;
    solve(n, 1, 3, 2);
    return 0;
}