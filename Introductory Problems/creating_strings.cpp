#include<iostream>
#include<unordered_set>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


unordered_set<string> result;

void populate(queue<char> buff, string ans){
    int sz = buff.size();
    if(sz==1){
        string pass = ans;
        pass += buff.front();
        result.insert(pass);
        return;
    }
    while(sz--){
        string pass = ans;
        char res = buff.front();
        buff.pop();
        pass += res;
        populate(buff, pass);
        buff.push(res);
    }
}


int main(){
    string s;
    cin>>s;
    queue<char> buff;
    for(char ch: s)buff.push(ch);
    populate(buff, "");
    cout<<result.size()<<endl;
    vector<string> objs(result.begin(), result.end());
    sort(objs.begin(), objs.end());
    for(string res: objs)cout<<res<<endl;
    return 0;
}