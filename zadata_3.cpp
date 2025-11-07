#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, l;
    cin >> n >> k >> l;

    vector<long long> plants(n);
    for (int i = 0; i < n; i++)
    {
        cin >> plants[i];
    }

    priority_queue<long long> pq;
    for (long long cost : plants)
    {
        pq.push(cost);
    }

    long long total = 0;
    int flowersNeeded = k;

    while (flowersNeeded > 0 && !pq.empty())
    {
        long long mostExpensive = pq.top();
        pq.pop();

        int take = min(l, flowersNeeded);
        total += mostExpensive * take;
        flowersNeeded -= take;
    }

    cout << total << endl;
    return 0;
}