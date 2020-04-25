#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
#define MOD 1000000007
lli fastPower(lli base, lli exponent)
{
    lli result = 1;
    base = base % MOD;
    if (base == 0)
        return base;
    while (exponent)
    {
        if (exponent & 1)
            result = (result * base) % MOD;
        exponent >>= 1;
        base = (base * base) % MOD;
    }
    return result;
}
void solve()
{
    lli n = 0, a = 0;
    cin >> n >> a;
    lli valueOfMatrixElement = 1;
    lli result = 0, p = 0, num = 1;
    for (lli i = 1; i <= n; i++)
    {
        p = fastPower((a * valueOfMatrixElement) % MOD, num);
        num += 2;
        result = (result + p) % MOD;
        valueOfMatrixElement = (valueOfMatrixElement * p) % MOD;
    }
    cout << result << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}