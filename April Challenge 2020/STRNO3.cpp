#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MAXN 100000
lli y = 0;
void sieve(lli sv[], lli x)
{
    sv[1] = 1;
    for (lli i = 2; i <= x; i++)
        sv[i] = i;
    for (lli i = 4; i <= x; i += 2)
        sv[i] = 2;
    for (lli i = 3; i * i <= x; i++)
    {
        if (sv[i] == i)
        {
            for (lli j = i * i; j <= x; j += i)
            {
                if (sv[j] == j)
                    sv[j] = i;
            }
        }
    }
}
vector<lli> primeFactorise(lli sv[], lli x)
{
    vector<lli> res;
    while (x != 1)
    {
        res.push_back(sv[x]);
        x = x / sv[x];
    }
    return res;
}
void solve()
{
    lli x = 0, k = 0;
    cin >> x >> k;
    lli sv[x + 1];
    sieve(sv, x);
    vector<lli> res = primeFactorise(sv, x);
    lli y = res.size();
    lli count[y + 1];
    memset(count, 0, sizeof(count));
    for (auto i : res)
        count[i]++;
    for (lli i = 1; i <= y; i++)
    {
        if (count[i] != 0)
            count[i]++;
    }
    lli out = 1;
    for (lli i = 1; i <= y; i++)
    {
        if (count[i] != 0)
            out *= count[i];
    }
    if (out >= k)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}