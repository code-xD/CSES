#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<char> letters;
    int chars[26] = {0};
    string s;
    cin>>s;
    for(char ch: s){
        chars[ch-'A']++;
        letters.insert(ch);
    }
    int odd = 0;
    for(int freq: chars)if(freq % 2)odd++;
  
    if(odd > 1)cout<<"NO SOLUTION";
    else{
        string ans = "";
        char mid = 0;
        for(auto itr : letters){
            if(chars[itr - 'A'] % 2)mid = itr;
            else{
                int freq = chars[itr - 'A'] / 2;
                while(freq--)ans += itr;
            }
        }
        int i = ans.length();
        if(mid!=0){
            int freq = chars[mid - 'A'];
            while(freq--)ans += mid;
        }
        while(i--)ans += ans[i];
        cout<<ans;
    }
    return 0;
}