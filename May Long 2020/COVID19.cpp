//Roshan Aji Cherian(roshanaji777)
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    lli n = 0;
    cin >> n;
    lli postionArray[n];
    for (lli i = 0; i < n; i++)
        cin >> postionArray[i];
    lli bestPossible = INT_MAX, worstPossible = INT_MIN;
    lli i = 0;
    while (i < n)
    {
        lli currentPostion = i;
        lli forwardPostion = i + 1, forwardCount = 0;
        //forward count from a postion
        while (abs(postionArray[forwardPostion] - postionArray[currentPostion]) <= 2 && forwardPostion < n)
        {
            currentPostion = forwardPostion;
            forwardPostion++;
            forwardCount++;
        }
        currentPostion = i;
        lli backwardPostion = i - 1, backwardCount = 0;
        //backward count from a  postion
        while (abs(postionArray[backwardPostion] - postionArray[currentPostion]) <= 2 && backwardPostion >= 0)
        {
            currentPostion = backwardPostion;
            backwardPostion--;
            backwardCount++;
        }
        lli totalCount = 1 + backwardCount + forwardCount;
        worstPossible = max(worstPossible, totalCount);
        bestPossible = min(bestPossible, totalCount);
        i++;
    }
    cout << bestPossible << ' ' << worstPossible << '\n';
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