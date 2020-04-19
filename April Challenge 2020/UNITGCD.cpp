#include <bits/stdc++.h>
using namespace std;
bool checkprime(int x)
{
    if (x <= 1)
        return false;
    if (x <= 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;

    for (int i = 5; i * i <= x; i = i + 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;

    return true;
}
void solve()
{
    int n = 0;
    cin >> n;
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    vector<int> primes;
    primes.push_back(1);
    visited[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (checkprime(i))
        {
            primes.push_back(i);
            visited[i] = true;
        }
    }
    vector<int> squares;
    for (int i = 2; i * i <= n; i++)
    {
        squares.push_back(i * i);
        visited[i * i] = true;
    }
    vector<int> res[n + 1];
    int prod[n + 1];
    memset(prod, 1, sizeof(prod));
    int k = 0;
    for (int i = 4; i <= n; i++)
    {
        if (!visited[i])
        {
            res[k].push_back(i);
            prod[k] *= i;
            for (int j = i; j <= n; j++)
            {
                if (!visited[j])
                {
                    if ((__gcd(prod[k], j) == 1) || (i == j))
                    {

                        if (i != j)
                        {
                            res[k].push_back(j);
                            prod[k] *= j;
                            visited[j] = true;
                        }
                    }
                }
            }
            visited[i] = true;
            k++;
        }
    }
    cout << k + 2 << '\n';
    for (int i : primes)
        cout << i << ' ';
    cout << '\n';
    for (int i : squares)
        cout << i << ' ';
    for (int i = 0; i <= k; i++)
    {
        cout << '\n';
        for (int j : res[i])
            cout << j << ' ';
    }
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
