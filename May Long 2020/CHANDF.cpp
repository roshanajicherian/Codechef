#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli functionCalc(lli x, lli y, lli z)
{
    return (x & z) * (y & z);
}
void solve()
{
    lli x = 0, y = 0, l = 0, r = 0;
    cin >> x >> y >> l >> r;
    lli functionXMax = INT_MIN, zValX = 0;
    lli functionYMax = INT_MIN, zValY = 0;
    lli functionRMax = INT_MIN, zValR = 0;
    for (lli i = 2; i >= 0; i--)
    {
        lli tempX = 0, tempY = 0, tempR = 0;
        if (x - i >= 0 && x - i <= r)
            tempX = functionCalc(x, y, x - i);
        if (y - i >= 0 && y - i <= r)
            tempY = functionCalc(x, y, y - i);
        if (r - i >= 0)
            tempR = functionCalc(x, y, r - i);
        if (tempX > functionXMax)
        {
            functionXMax = tempX;
            zValX = x - i;
        }
        if (tempY > functionYMax)
        {
            functionYMax = tempY;
            zValY = y - i;
        }
        if (tempX > functionRMax)
        {
            functionRMax = tempR;
            zValR = r - i;
        }
    }
    lli res = 0;
    if (functionXMax >= functionYMax && functionXMax >= functionRMax)
        res = zValX;
    else if (functionYMax >= functionXMax && functionYMax >= functionRMax)
        res = zValY;
    else if (functionRMax >= functionXMax && functionRMax >= functionYMax)
        res = zValR;
    cout << res << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}