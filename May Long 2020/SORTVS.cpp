#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0, m = 0, time = 0;
    cin >> n >> m;
    lli A[n + 1], robot[m];
    for (lli i = 1; i <= n; i++)
        cin >> A[i];
    for (lli i = 0; i < m; i++)
        cin >> robot[i];
    for (lli i = 1; i <= n; i++)
    {
        if (A[i] != i)
        {
            for (lli j = i + 1; j <= n; j++)
            {
                if (i == A[j])
                {
                    time++;
                    swap(A[i], A[j]);
                }
            }
        }
    }
    cout << time << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}