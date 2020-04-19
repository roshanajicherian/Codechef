#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool checkprime(lli x)
{
    if (x <= 1)
        return false;
    if (x <= 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;

    for (lli i = 5; i * i <= x; i = i + 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;

    return true;
}
void solve()
{
    lli n = 0;
    cin >> n;
    vector<lli> matrix[n + 1];
    lli gcd[n + 1];
    for (lli i = 0; i < n; i++)
        gcd[i] = 1;
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    lli k = 0;
    // for (int i = 2; i <= n; i++)
    // {
    //     if (checkprime(i))
    //     {
    //         matrix[0].push_back(i);
    //         visited[i] = true;
    //     }
    // }
    int maxk = INT_MIN;
    for (lli i = 1; i <= n; i++)
    {
        k = 1;
        if (!visited[i])
        {
            lli g = __gcd(gcd[k], i);
            while (__gcd(gcd[k], i) != 1)
            {
                k++;
                if (k > maxk)
                    maxk = k;
            }
            matrix[k].push_back(i);
            gcd[k] *= i;
        }
    }
    cout << maxk << '\n';
    for (lli i = 1; i <= maxk; i++)
    {
        for (auto it = matrix[i].begin(); it != matrix[i].end(); it++)
        {
            cout << *it << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}