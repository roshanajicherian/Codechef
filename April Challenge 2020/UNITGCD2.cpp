#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
int HF[MAXN];
int greatestfac(int n)
{
    memset(HF, sizeof(HF), 0);
    HF[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (HF[i] == 0)
        {
            HF[i] = i;
            for (int j = 2 * i; j <= n; j += i)
            {
                if (HF[j] == 0)
                    HF[j] = i;
            }
        }
    }
}
void solve()
{
    int n = 0, k = 0;
    cin >> n;
    bool visited[n + 1];
    vector<int> res[n + 1];
    memset(visited, false, sizeof(visited));
    greatestfac(n);
    bool first = false;
    for (int i = 1; i <= n; i++)
    {
        for(int j=i;j<=n;j++)//if j=0 or i
        {

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