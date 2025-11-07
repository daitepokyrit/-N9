#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, d;
    cin >> n >> d;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long l = 0, r = a.back() - a.front(), res = r;
    auto ok = [&](long long x)
    {
        int c = 1;
        long long mn = a[0], mx = a[0];
        for (int i = 1; i < n; i++)
        {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            if (mx - mn > x)
            {
                c++;
                mn = mx = a[i];
            }
        }
        return c <= d;
    };
    while (l <= r)
    {
        long long m = (l + r) / 2;
        if (ok(m))
            res = m, r = m - 1;
        else
            l = m + 1;
    }
    cout << res;
}