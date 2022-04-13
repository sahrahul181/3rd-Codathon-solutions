#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &a, int &n)
{

    int i = 1;
    while (i < n)
    {
        if (a[i] - a[i - 1] < 0)
            i++;
        else
            break;
    }
    while (i < n)
    {
        if (a[i] - a[i - 1] > 0)
            i++;
        else
            break;
    }
    if (i == n)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        if (n > 2)
            solve(v, n);
        else
            cout << "true" << endl;
    }

    return 0;
}
