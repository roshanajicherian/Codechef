#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x = 0, y = 0, l = 0, r = 0;
    cin >> x >> y >> l >> r;
    int orResult = x | y;
    int functionMax = LONG_MIN;
    int result = 0;
    for (int z = 0; z <= orResult && z <= r; z++)
    {
        int functionCalc = (x & z) * (y & z);
        if (functionCalc > functionMax)
        {
            functionMax = functionCalc;
            result = z;
        }
    }
    cout << result << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}