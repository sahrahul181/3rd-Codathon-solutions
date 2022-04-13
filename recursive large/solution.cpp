#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, p;
    cin >> s;
    p = s;
    int n = s.length();

    vector<string> v;
    vector<short> f(26, 0);
    int curr = 1;
    for (int i = 0; i < n; i++)
        f[p[i] - 'a']++;
    for (auto i : f)
    {
        if (i != 0)
            curr *= i;
    }
    while (next_permutation(p.begin(), p.end()))
    {
        v.push_back(p);
    }
    for (auto i : v)
    {
        for (int j = 1; j <= curr; j++)
            cout << i << endl;
    }

    return 0;
}
