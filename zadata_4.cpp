#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else if (c == ')' || c == ']' || c == '}')
        {
            if (st.empty())
            {
                cout << "no";
                return 0;
            }
            char t = st.top();
            st.pop();
            if ((t == '(' && c != ')') || (t == '[' && c != ']') || (t == '{' && c != '}'))
            {
                cout << "no";
                return 0;
            }
        }
    }
    cout << (st.empty() ? "yes" : "no");
}