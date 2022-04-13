#include <bits/stdc++.h>
using namespace std;

void helper(int r, int c, vector<vector<int>> &a, map<pair<int, int>, map<int, int>> &m, vector<map<int, int>> &row, vector<map<int, int>> &col, int &n)
{
    if (r == n)
    {
        for (auto i : a)
        {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
        return;
    }
    else if (c == n)
    {
        helper(r + 1, 0, a, m, row, col, n);
        return;
    }
    else if (a[r][c] != 0)
    {
        helper(r, c + 1, a, m, row, col, n);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        int rw=r/3,cl=c/3;
        if(!m[{rw,cl}][i] && !row[r][i] && !col[c][i]){
            m[{rw,cl}][i]=1;
            row[r][i]=1;
            col[c][i]=1;
            a[r][c]=i;
            helper(r,c+1,a,m,row,col,n);
            m[{rw,cl}][i]=0;
            row[r][i]=0;
            col[c][i]=0;
            a[r][c]=0;
        }
    }
    
}

void solve(vector<vector<int>> &a, int &n)
{
    map<pair<int, int>, map<int, int>> m;
    vector<map<int, int>> row(n);
    vector<map<int, int>> col(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                m[{i / 3, j / 3}][a[i][j]] = 1;
                row[i][a[i][j]] = 1;
                col[j][a[i][j]] = 1;
            }
        }
    }

    helper(0, 0, a, m, row, col, n);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (auto &i : a)
    {
        i.resize(n);
        for (auto &j : i)
            cin >> j;
    }
    solve(a, n);

    return 0;
}
