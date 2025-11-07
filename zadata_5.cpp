#include <iostream>
#include <vector>
#include <unordered_set>
#include <cctype>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t, w;
    unordered_set<string> u;
    vector<string> r;
    while (getline(cin, t))
        s += t + ' ';
    for (char c : s)
    {
        if (isalpha((unsigned char)c) || (c & 128) || c == '-')
            w.push_back(tolower((unsigned char)c));
        else
        {
            while (w.size() && w.front() == '-')
                w.erase(w.begin());
            while (w.size() && w.back() == '-')
                w.pop_back();
            if (w.size() && u.insert(w).second)
                r.push_back(w);
            w.clear();
        }
    }
    if (w.size() && u.insert(w).second)
        r.push_back(w);
    for (string &x : r)
        cout << x << "\n";
}