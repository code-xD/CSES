#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> price;
    vector<int> pages;
    for (int i = 0; i < n; i++)
    {
        int pr;
        cin >> pr;
        price.push_back(pr);
    }
    for (int i = 0; i < n; i++)
    {
        int pg;
        cin >> pg;
        pages.push_back(pg);
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    // dp[i][j] - max pages bought with atmost i books and target price = j.
    // dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i-1]] + pages[i-1]); i-1 due to zero index.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j]; // if book-i is not considered.
            if (price[i - 1] <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}