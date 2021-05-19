#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool compByEnd(const pair<ll,ll> &a, const pair<ll,ll> &b){
    if(a.second == b.second)return a.first < b.first;
    return a.second < b.second;
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<ll, ll>> arr;
    for(int i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(), arr.end(), compByEnd);
    multiset<ll> booked;
    int ans = n;
    for(int i=0; i<n; i++){
        // if no movie is being watched then add the person to the movie.
        if (booked.size() == 0)booked.insert(arr[i].second);
        else{
            // if the movie which ended first is before the next movie started then erase the previous movie and add this.
            auto it = booked.upper_bound(arr[i].first);
            // if it = booked.begin() this means all the movies are ongoing
            if(it != booked.begin()){
                it--; // go to the previous movie which has end time <= to the movie which we have to book.
                booked.erase(it);
                booked.insert(arr[i].second);
            }
            // however if the new movie is colliding with all the current booked movies. 
            else{
                if(booked.size() < k)
                    booked.insert(arr[i].second); //We need to check if we have a person available.
                else ans--; // this means you can't watch this movie.
            }
        }
    }
    cout<<ans<<endl;
    return 0;

}