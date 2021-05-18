#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> arr;
    for (int i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        arr.push_back(num);
    }
    map<ll, int> prefix_rem;
    prefix_rem[0]++;
    ll rsum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        rsum += arr[i];
        ll mod = (rsum < 0) ? ((rsum % n + n) % n) : (rsum % n); // It's important to understand how C++ deals with modulus.
        ans += prefix_rem[mod];
        prefix_rem[mod]++;
    }
    cout << ans << endl;
    return 0;
}