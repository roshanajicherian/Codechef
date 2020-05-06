#include <bits/stdc++.h>
using namespace std;
#define MAXN 400
typedef long long int lli;
lli kValues[MAXN + 1];
void init()
{
    kValues[3] = 1;
    for (lli i = 4; i <= 400; i++)
    {
        if (i & 1)
            kValues[i] = kValues[i - 1];
        else
            kValues[i] = i / 2;
    }
}
void solve()
{
    lli n = 0, k = 0;
    cin >> n >> k;
    vector<int> result[k];
    lli A[n + 1];
    for (lli i = 1; i <= n; i++)
        cin >> A[i];
    //lli movesRequired = kValues[n];
    lli start = 1, end = n, v1 = end - 1;
    int count = 0;
    //cout << movesRequired << '\n';
    while (start < end)
    {
        if (end != start + 1)
        {
            //cout << v1 << ' ' << start << ' ' << end << '\n';
            result[count].push_back(v1);
            result[count].push_back(start);
            result[count].push_back(end);
        }
        else
        {
            //cout << start << ' ' << end + 1 << ' ' << end << '\n';
            result[count].push_back(start);
            result[count].push_back(end + 1);
            result[count].push_back(end);
        }
        start++;
        v1--;
        end--;
        count++;
    }
    cout << count << '\n';
    for (int i = 0; i < count; i++)
    {
        for (auto j : result[i])
        {
            cout << j << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    //init();
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}