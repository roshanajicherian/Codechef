#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x = 0, y = 0, l = 0, r = 0;
    cin >> x >> y >> l >> r;
    int res = 0;
    if (x == 0 || y == 0)
        res = 0;
    else
        res = x | y;
    cout << res << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}