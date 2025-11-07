#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, k, l;
    cin >> n >> k >> l;
    vector<long long> a(n), v;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (long long x : a)
        for (int j = 0; j < l; j++)
            v.push_back(x);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long s = 0;
    for (int i = 0; i < k; i++)
        s += v[i];
    cout << s;
}