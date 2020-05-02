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
    lli queries[q];
    lli maxc = INT_MIN;
    for (lli i = 0; i < q; i++)
    {
        cin >> queries[i];
        maxc = max(maxc, queries[i]);
    }
    lli pendingQueue = n;
    lli queryresult[maxc + 1];
    memset(queryresult, 0, sizeof(queryresult));
    lli j = 1;
    while (maxc > 0)
    {
        for (lli i = 0; i < CHARMAX; i++)
        {
            if (letterCount[i] > 0)
            {
                letterCount[i]--;

                pendingQueue--;
            }
        }
        queryresult[j] = pendingQueue;
        maxc--;
        j++;
    }
    for (lli i = 0; i < q; i++)
    {
        cout << queryresult[queries[i]] << '\n';
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