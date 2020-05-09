#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0;
    cin >> n;
    lli A[n];
    for (lli i = 1; i <= n; i++)
        cin >> A[i];
    sort(A + 1, A + n + 1);
    lli movesRequired = 0, previousMove = -100;
    for (lli i = 1; i <= n; i++)
    {
        if (i == n)
        {
            if (A[i - 1] != A[i] - 1 && A[i] != previousMove + 1)
            {
                movesRequired++;
                previousMove = A[i] + 1;
            }
        }
        else if (i < n)
        {
            if ((A[i + 1] != A[i] + 1) && (A[i] != previousMove + 1))
            {
                movesRequired++;
                previousMove = A[i] + 1;
            }
            else
                previousMove = A[i];
        }
    }
    cout << movesRequired << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}