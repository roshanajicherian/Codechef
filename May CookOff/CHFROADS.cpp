#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool isPowerOfTwo(int x)
{
    return x && (!(x & (x - 1)));
}
void solve()
{
    lli n = 0;
    cin >> n;
    if (isPowerOfTwo(n))
    {
        cout << -1 << '\n';
        return;
    }
    lli ans = 0;
    ans = (n + 1) / 2;
    ans--;
    n >>= 1;
    lli i = 1;
    while (n)
    {
        lli noOfElementsInGroup = (n + 1) / 2;
        lli value = noOfElementsInGroup * (1 << i);
        ans = ans + value;
        i++;
        n >>= 1;
    }
    cout << ans << '\n';
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