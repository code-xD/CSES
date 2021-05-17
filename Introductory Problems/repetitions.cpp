#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    string seq;
    cin>>seq;
    int count = 1;
    int max_count = 1;
    for(int i=1;i<seq.size();i++){
        if(seq[i] == seq[i-1])count++;
        else count = 1;
        max_count = max(max_count, count);
    }
    cout<<max_count;
    return 0;
}