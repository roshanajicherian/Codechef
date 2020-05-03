#include <bits/stdc++.h>
using namespace std;
#define MAXN 160001
typedef long long int lli;
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
    lli V[k + 1][3];
    lli A[n + 1];
    for (lli i = 1; i <= n; i++)
        cin >> A[i];
    lli start = 1, end = n, count = 0;
    while (start < end)
    {
        lli maxi = INT_MIN, mini = INT_MAX;
        lli maxiIndex = 0, miniIndex = 0;
        for (lli i = start; i <= end; i++)
        {
            if (A[i] > maxi)
            {
                maxi = A[i];
                maxiIndex = i;
            }
            if (A[i] < mini)
            {
                mini = A[i];
                miniIndex = i;
            }
        }
        if (end == start + 1)
        {
            count++;
            V[count - 1][0] = end;
            V[count - 1][1] = start;
            V[count - 1][2] = start - 1;
            break;
        }
        else
        {
            lli v1 = 0, v2 = 0, v3 = 0, tv1 = 0, tv2 = 0, tv3 = 0;
            v3 = miniIndex, v2 = maxiIndex, v1 = miniIndex - 1;
            count++;
            V[count - 1][0] = v1;
            V[count - 1][1] = v2;
            V[count - 1][2] = v3;
            tv2 = A[v2];
            A[v2] = A[v1];
            tv3 = A[v3];
            A[v3] = tv2;
            tv1 = A[tv1];
            A[v1] = tv3;
        }
        start++;
        end--;
    }
    cout << count << '\n';
    for (lli i = 0; i < count; i++)
    {
        for (lli j = 0; j < 3; j++)
            cout << V[i][j] << ' ';
        cout << '\n';
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}