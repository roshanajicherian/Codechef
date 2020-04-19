#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool checkproduct(vector<lli> A, lli prod)
{
    unordered_map<lli, lli> S;
    for (lli i = 0; i <= prod; i++)
    {
        S[i * i] = i * i;
    }
    for (lli i = 0; i * i <= prod; i++)
    {
        if (S.find(prod + (i * i)) != S.end())
            return true;
    }
    return false;
}
void solve()
{
    lli n = 0;
    cin >> n;
    lli A[n];
    for (lli i = 0; i < n; i++)
        cin >> A[i];
    vector<lli> check;
    lli count = 0;
    for (lli i = 0; i < n; i++)
    {
        check.clear();
        lli prod = 1;
        for (lli j = i; j < n; j++)
        {
            prod *= A[j];
            check.push_back(A[j]);
            if (checkproduct(check, prod))
                count++;
        }
    }
    cout << count << '\n';
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