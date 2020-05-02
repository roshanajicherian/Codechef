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
    lli letterCount[CHARMAX], temporaryLetterCount[CHARMAX];
    memset(letterCount, 0, sizeof(letterCount));
    for (lli i = 0; i < S.length(); i++)
    {
        letterCount[S[i] - 'a']++;
    }
    while (q--)
    {
        cin >> c;
        lli pendingQueue = S.length();
        for (lli i = 0; i < CHARMAX; i++)
            temporaryLetterCount[i] = letterCount[i];
        while (c > 0)
        {
            for (lli i = 0; i < CHARMAX; i++)
            {
                if (temporaryLetterCount[i] > 0)
                {
                    temporaryLetterCount[i]--;
                    pendingQueue--;
                }
            }
            c--;
        }
        cout << pendingQueue << '\n';
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