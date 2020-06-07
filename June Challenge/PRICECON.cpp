#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
    lli diffrence = 0;
    vector<lli> A(n);
    for (auto &it : A)
    {
        cin >> it;
        if (it > k)
            diffrence += (it - k);
    }
    cout << diffrence << '\n';
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