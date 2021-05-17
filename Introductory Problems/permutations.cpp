#include<iostream>
#include<vector>
using namespace std;

int main(){
   int n = 0;
   cin>>n;
   if(n==1)cout<<"1";
   else if(n==4)cout<<"2 4 1 3";
   else if(n<=4)cout<<"NO SOLUTION";
   else{
      int i = n;
      int j = n/2;
      while(i > n/2 || j >=1){
         if(i>n/2){
            cout<<i<<" ";
            i--;
         }
         if(j>=1) {
            cout<<j<<" ";
            j--;
         }
      }
   }
   return 0;
}
