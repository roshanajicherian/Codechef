#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    string S;
    cin >> S;
    lli n = S.length();
    bool isPair[n];
    lli pairCount = 0;
    memset(isPair, 0, sizeof(isPair));
    for (lli i = 0; i < n; i++)
    {
        if (isPair[i] == false && S[i] == 'y')
        {
            if (i > 0 && isPair[i - 1] == false && S[i - 1] == 'x')
            {
                isPair[i - 1] = isPair[i] = true;
                pairCount++;
            }
            else if (i < n - 1 && isPair[i + 1] == false && S[i + 1] == 'x')
            {
                isPair[i + 1] = isPair[i] = true;
                pairCount++;
            }
        }
    }
    cout << pairCount << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}