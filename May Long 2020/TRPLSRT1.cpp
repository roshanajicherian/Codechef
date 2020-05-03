#include <bits/stdc++.h>
using namespace std;
#define MAXN 400
typedef long long int lli;
lli kValues[MAXN + 1];
void init()
{
    kValues[3] = 1;
    for (lli i = 4; i <= 400; i++)
    {
        if (i & 1)
            kValues[i] = kValues[i - 1];
        else
            kValues[i] = i / 2;
    }
}
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
    lli A[n + 1];
    for (lli i = 1; i <= n; i++)
        cin >> A[i];
    lli movesRequired = kValues[n];
    lli start = 1, end = n, v1 = end - 1;
    cout << movesRequired << '\n';
    while (start < end)
    {
        if (end != start + 1)
        {
            cout << v1 << ' ' << start << ' ' << end << '\n';
        }
        else
        {
            cout << start << ' ' << end + 1 << ' ' << end << '\n';
        }
        start++;
        v1--;
        end--;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    init();
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}