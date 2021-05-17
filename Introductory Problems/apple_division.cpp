#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ull;

ull calculateMin(queue<ull> buff, ull total, ull curr){
    if(buff.empty())return abs(total - 2 * curr);
    ull front = buff.front();
    ull diff = abs(total - 2 * curr);
    diff = min(abs(total - 2 * curr), abs(total - 2 * (curr + front)));
    buff.pop();
    ull minVals[] = {calculateMin(buff, total, curr), calculateMin(buff, total, curr + front), diff};
    return *min_element(minVals, minVals + 3);
}


int main(){
    int n;
    cin>>n;
    ull total = 0;
    queue<ull> buff;
    while(n--){
        ull no;
        cin>>no;
        buff.push(no);
        total += no;
    }
    cout<<calculateMin(buff, total, 0);
    return 0;
}