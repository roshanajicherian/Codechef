#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define CHARMAX 26
void solve()
{
    lli n = 0, q = 0, c = 0;
    string S;
    cin >> n >> q;
    cin >> S;
    lli letterCount[CHARMAX];
    memset(letterCount, 0, sizeof(letterCount));
    for (lli i = 0; i < S.length(); i++)
        letterCount[S[i] - 'a']++;
    vector<lli> letterCountGreaterThan1;
    lli maxi = LLONG_MIN;
    for (lli i = 0; i < CHARMAX; i++)
        if (letterCount[i] > 1)
        {
            if (letterCount[i] > maxi)
                maxi = letterCount[i];
            letterCountGreaterThan1.push_back(letterCount[i]);
        }
    lli pendingQueue = 0;
    while (q--)
    {
        pendingQueue = 0;
        lli c = 0;
        cin >> c;
        if (c == 0)
            cout << n << '\n';
        else if (c >= maxi)
            cout << 0 << '\n';
        else
        {
            for (lli i : letterCountGreaterThan1)
            {
                if (i - c > 0)
                    pendingQueue += (i - c);
            }
            cout << pendingQueue << '\n';
        }
    }
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