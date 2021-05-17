#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

/*
    Approach: Person A starts from the largest book and Person B the second largest one. 
    Since second largest <= largest book as soon as B completes reading the book will always be to A.
    This cycle continues till B reads all the books except the last one. 
    Now B can pick the largest book iff the time taken to read all the other books has elasped the largest book.
    Else it needs to wait for A to read the largest book and then take it. Therefore the answer will always be max(sum_of_all_books, 2 * largest_book).
*/

int main(){
    ll book, max_book, sum = 0;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>book;
        if(i==0)max_book = book;
        else max_book = max(book , max_book);
        sum += book;
    }
    cout<<max(sum, 2 * max_book)<<endl;
    return 0;
}