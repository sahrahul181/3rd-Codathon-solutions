#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int t;
    cin>>t;
    while (t--)
    {
        cin >> s;
        bool flag = false;
        int n = s.length();
        string curr, first;
        for (int i = 1; i <= n / 2; i++)
        {
            string res = "";
            res = first = curr = s.substr(0, i);

            while (res.length() < s.length())
            {
                int j, n = curr.length();
                

                for (j = n - 1; j >= 0 && curr[j]=='9'; j--)
                {
                    curr[j]='0';
                }
                if (j < 0)
                    curr = "1" + curr;
                else 
                  curr[j] += 1;

                

                res += curr;
            }
            if (res == s)
            {
                flag = true;
                break;
            }
        }
        if (flag && curr[0]!='0')
            cout << "YES " << first << endl;
        else if (flag && curr[0]=='0' && curr.length()==1)
            cout << "YES " << first << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
