#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MAXN int(1e7 + 1)
#define MOD int(1e9 + 7)
lli factor[MAXN];
void findGreatestFactor()
{
    factor[1] = 1;
    for (lli i = 2; i < MAXN; i++)
        factor[i] = i;
    for (lli i = 4; i < MAXN; i += 2)
        factor[i] = 2;
    for (lli i = 3; i * i < MAXN; i++)
    {
        if (factor[i] == i)
        {
            for (lli j = i * i; j < MAXN; j += i)
            {
                if (factor[j] == j)
                    factor[j] = i;
            }
        }
    }
}
bool checkprime(lli n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (lli i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
lli smallest(lli n)
{
    if (n == 1)
        return 1;
    lli c = 1;
    lli ans = 1;
    lli dup = factor[n];
    lli j = n / factor[n];
    while (j != 1)
    {
        if (factor[j] == dup)
            c += 1;
        else
        {
            dup = factor[j];
            ans *= (c + 1);
            c = 1;
        }
        j = j / factor[j];
    }
    ans *= (c + 1);
    return ans;
}
lli calc(lli n)
{
    for (lli i = 1;; i++)

        if (smallest(i) == n)
            return i;
}
lli sievefactor(lli a)
{
    lli count = 0;
    while (a != 1)
    {
        if (checkprime(factor[a]))
            count++;
        a = a / factor[a];
    }
    return count;
}
void solve()
{
    lli x = 0, k = 0;
    cin >> x >> k;
    lli smallest = calc(x);
    lli factors = sievefactor(smallest);
    if (factors == k)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}
int main()
{
    findGreatestFactor();
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}