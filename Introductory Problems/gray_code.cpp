#include<iostream>
#include<vector>
using namespace std;

vector<string> generator(int n){
    if(n==1)return vector<string>{"0", "1"};
    vector<string> result;
    vector<string> ret = generator(n-1);
    for(int i=0; i<ret.size(); i++)result.push_back("0" + ret[i]);
    for(int i=ret.size()-1; i>=0; i--)result.push_back("1" + ret[i]);
    return result;
}

int main(){
    int n;
    cin>>n;
    for(string s: generator(n))cout<<s<<endl;
    return 0;
}