#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0, k = 0;
    cin >> n >> k;
    string S;
    cin >> S;
    int head[n], tail[n];
    memset(head, 0, sizeof(head));
    memset(tail, 0, sizeof(tail));
    for (int i = 1; i < n; i++)
    {
        if (S[i - 1] == '1')
            head[i] = head[i - 1] + 1;
        else
            head[i] = 0;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (S[i + 1] == '1')
            tail[i] = tail[i + 1] + 1;
        else
            tail[i] = 0;
    }
    int result = INT_MIN;
    for (int i = 0; i+k <= n; i++)
        result = max(result, k + head[i] + tail[k + i - 1]);
    cout << result << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}