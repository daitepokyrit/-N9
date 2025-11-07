#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));
    vector<vector<long long>> dp(n, vector<long long>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    dp[0][0] = a[0][0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + a[i][0];
    }

    for (int j = 1; j < m; j++)
    {
        dp[0][j] = dp[0][j - 1] + a[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }

    vector<pair<int, int>> path;
    int i = n - 1, j = m - 1;

    while (i > 0 || j > 0)
    {
        path.push_back({i, j});

        if (i == 0)
        {

            j--;
        }
        else if (j == 0)
        {

            i--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {

            i--;
        }
        else
        {

            j--;
        }
    }

    // Добавляем стартовую точку
    path.push_back({0, 0});

    reverse(path.begin(), path.end());

    for (auto &point : path)
    {
        cout << point.first << " " << point.second << "\n";
    }

    return 0;
}