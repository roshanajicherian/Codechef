#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli x = 0, y = 0, l = 0, r = 0;
    cin >> x >> y >> l >> r;
    lli functionMax = INT_MIN, z = 0;
    for (lli i = r; i >= l; i--)
    {
        lli functionValue = (x & i) * (y & i);
        if (functionValue > functionMax)
        {
            functionMax = functionValue;
            z = i;
            continue;
        }
        if (functionValue < functionMax)
        {
            break;
        }
    }
    cout << z << '\n';
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