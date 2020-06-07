#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0;
    cin >> n;
    vector<lli> A(n);
    for (auto &it : A)
        cin >> it;
    map<lli, lli> moneyCount;
    for (lli i = 0; i < n; i++)
    {
        if (A[i] > 5)
        {
            lli difference = 5;
            if (moneyCount[difference] > 0)
            {
                moneyCount[difference]--;
                moneyCount[A[i]]++;
                continue;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
        else
            moneyCount[A[i]]++;
    }
    cout << "YES\n";
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}