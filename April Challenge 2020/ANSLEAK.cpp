#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    int A[n][k];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            cin >> A[i][j];
    }
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        cout << (rand() % m) + 1 << ' ';
    }
    cout << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
}