#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0, k = 0;
    cin >> n >> k;
    int A[n + 1];
    int visited[n + 1];
    vector<pair<int, int>> dobules;
    vector<tuple<int, int, int>> triples;
    for (int i = 1; i <= n; ++i)
    {
        visited[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
        {
            vector<int> cycles;
            int j = i;
            while (!visited[j])
            {
                visited[j] = true;
                cycles.push_back(j);
                j = A[j];
            }
            while (cycles.size() > 2)
            {
                int z = cycles.back();
                cycles.pop_back();
                int y = cycles.back();
                cycles.pop_back();
                int x = cycles.back();
                if (cycles.size() == 1)
                    cycles.pop_back();
                triples.push_back(tie(x, y, z));
                k--;
            }
            if (cycles.size() == 2)
            {
                dobules.push_back(make_pair(cycles[0], cycles[1]));
            }
        }
    while (dobules.size() > 1)
    {
        pair<int, int> one = dobules.back();
        dobules.pop_back();
        pair<int, int> two = dobules.back();
        dobules.pop_back();
        triples.push_back(tie(one.second, two.first, two.second));
        triples.push_back(tie(one.first, one.second, two.first));
        k -= 2;
    }
    if (!dobules.empty())
        k = -1;
    if (k < 0)
        cout << -1 << '\n';
    else
    {
        cout << triples.size() << '\n';
        for (int i = 0; i < triples.size(); i++)
        {
            cout << get<0>(triples[i]) << ' ' << get<1>(triples[i]) << ' ' << get<2>(triples[i]) << '\n';
        }
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