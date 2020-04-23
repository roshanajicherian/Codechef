#include <bits/stdc++.h>
typedef long long lli;
using namespace std;
void solve()
{
    lli n = 0, q = 0;
    cin >> n >> q;
    lli currentLiftPostion = 0, totalFloorsCovered = 0;
    while (q--)
    {
        pair<lli, lli> query;
        cin >> query.first >> query.second;
        totalFloorsCovered += abs(currentLiftPostion - query.first);
        currentLiftPostion = query.first;
        totalFloorsCovered += abs(currentLiftPostion - query.second);
        currentLiftPostion = query.second;
    }
    cout << totalFloorsCovered << '\n';
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