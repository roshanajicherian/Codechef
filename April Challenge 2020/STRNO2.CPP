#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x = 0, k = 0;
    cin >> x >> k;
    if (x < k)
    {
        cout << 0 << '\n';
        return;
    }
    int second = 1;
    for (int i = 1; i <= k - 1; i++)
        second *= 2;
    int positions = k + second;
    if (positions <= x)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}