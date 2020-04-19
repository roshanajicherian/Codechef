#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define MAXN 1000000
void solve()
{
    int n = 0;
    int maxk = 0;
    cin >> n;
    vector<int> res[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        bool flg = false;
        while (true)
        {
            if (res[k].empty())
            {
                flg = true;
                res[k].push_back(i);
                break;
            }
            for (auto j : res[k])
            {
                if (__gcd(i, j) == 1)
                {
                    flg = true;
                    continue;
                }
                else
                {
                    k++;
                    maxk = max(maxk, k);
                    flg = false;
                    break;
                }
            }
            if (flg == true)
            {
                res[k].push_back(i);
                break;
            }
        }
    }
    cout << maxk + 1 << '\n';
    for (int i = 0; i <= maxk; i++)
    {
        cout << res[i].size() << ' ';
        for (int j : res[i])
            cout << j << ' ';
        cout << '\n';
    }
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}