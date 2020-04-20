#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

void solve()
{
    lli n = 0;
    cin >> n;
    lli A[n];
    lli powerOfTwo[n];
    memset(powerOfTwo, 0, sizeof(powerOfTwo[n]));
    //All numbers of the form 2*x does not form the required subarray.
    //From the total possible subarrays delete all the combinations which
    //donot satisfy the required condtion.
    for (lli i = 0; i < n; i++)
    {
        cin >> A[i];
        if (A[i] % 4 == 0)
            powerOfTwo[i] = 2;
        else if (A[i] % 2 == 0)
            powerOfTwo[i] = 1;
        else
            powerOfTwo[i] = 0;
    }
    lli totalSubsequnce = (n * (n + 1)) / 2;
    lli subArrayCount[3 * n];
    memset(subArrayCount, 0, sizeof(subArrayCount));
    subArrayCount[0]++;
    lli sumTillNow = 0;
    for (lli i = 0; i < n; i++)
    {
        sumTillNow += powerOfTwo[i];
        if (sumTillNow > 0)
            totalSubsequnce -= subArrayCount[sumTillNow - 1];
        subArrayCount[sumTillNow]++;
    }
    cout << totalSubsequnce << '\n';
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