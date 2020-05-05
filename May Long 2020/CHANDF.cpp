#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli x = 0, y = 0, l = 0, r = 0;
    cin >> x >> y >> l >> r;
    lli limitResult = (x & r) * (y & r);
    lli result = x | y;
    lli z = 0;
    if (result > r)
    {
        lli temporary = (result & r) - 1;
        lli newResult = (x & temporary) * (y & temporary);
        if (newResult > result)
            z = temporary;
        else
            z = r;
    }
    else
        z = result;
    cout << z << '\n';
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