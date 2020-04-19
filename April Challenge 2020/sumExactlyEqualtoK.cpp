/*Program for practice*/
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int k = 0;
    cin >> k;
    int sumSoFar = 0, subarrayCount = 0;
    unordered_map<int, int> subMap;
    for (int i = 0; i < n; i++)
    {
        sumSoFar += A[i];
        if (sumSoFar == k)
            subarrayCount++;
        if (subMap.find(sumSoFar - k) != subMap.end())
        {
            subarrayCount += subMap[sumSoFar - k];
        }
        subMap[sumSoFar]++;
    }
    cout << subarrayCount << '\n';
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}