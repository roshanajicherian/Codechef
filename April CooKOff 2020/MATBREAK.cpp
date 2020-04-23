#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long lli;
using namespace std;
lli fastPower(lli base, lli exponent)
{
    base = base % MOD;
    if (base == 0)
        return 0;
    lli result = 1;
    while (exponent > 0)
    {
        if (exponent & 1) //if exponent is odd
            result = (result * base) % MOD;
        exponent = exponent >> 1;
        base = (base * base) % MOD;
    }
    return result;
}
void solve()
{
    lli n = 0, a = 0;
    cin >> n >> a;
    lli elementInMatrix = a, sumOfMultipliers = 0;
    bool matrix[n][n];
    memset(matrix, true, sizeof(matrix));
    //FRIST STEP
    for (lli i = 1; i <= n; i++) //check here if always n steps are required
    {
        for (lli k = 1; k <= i - 1; k++)
            matrix[k][n - i + 1] = false;
        for (lli k = 1; n - i + k <= n; k++)
            matrix[i][n - i + k] = false;
        lli multiplier = fastPower(elementInMatrix, 2 * i - 1);
        sumOfMultipliers = (sumOfMultipliers % MOD + multiplier) % MOD;
        elementInMatrix *= multiplier;
    }
    cout << sumOfMultipliers << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
