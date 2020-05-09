#include <bits/stdc++.h>
using namespace std;
#define MAXN 400
typedef long long int lli;
lli kValues[MAXN + 1];
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
    vector<lli> result[k];
    lli A[n + 1];
    for (lli i = 1; i <= n; i++)
        cin >> A[i];
    lli B[7];
    lli start = 1, end = n, v1 = end - 1, count = 0;
    bool notPossible = false;
    while (start < end)
    {
        if (count >= k)
        {
            notPossible = true;
            break;
        }
        if (end != start + 1)
        {
            result[count].push_back(v1);
            result[count].push_back(start);
            result[count].push_back(end);
            B[start] = A[end];
            B[end] = A[start];
            B[v1] = A[v1];
        }
        else
        {
            result[count].push_back(start);
            result[count].push_back(end + 1);
            result[count].push_back(end);
            
        }
        start++;
        v1--;
        end--;
        count++;
    }
    // if (!notPossible)
    // {
    //     cout << count << '\n';
    //     for (lli i = 0; i < count; i++)
    //     {
    //         for (auto j : result[i])
    //         {
    //             cout << j << ' ';
    //         }
    //         cout << '\n';
    //     }
    // }
    // else
    //     cout << -1 << '\n';
    for (int i = 1; i <= n; i++)
        cout << B[i] << ' ';
    cout << '\n';
}
int main()
{
    //init();
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}