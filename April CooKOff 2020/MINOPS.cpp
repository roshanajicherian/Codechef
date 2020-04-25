#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
void solve()
{
    string S, R;
    cin >> S >> R;
    bool diffrentLettersEncountered = false;
    lli gapBetweenLetters = 0, k = 0, l = 0;
    vector<lli> gapsVector;
    for (lli i = 0; i < S.length(); i++)
    {
        if (S[i] == R[i])
        {
            if (diffrentLettersEncountered)
                gapBetweenLetters++;
        }
        else
        {
            if (!diffrentLettersEncountered)
                k++;
            l++;
            diffrentLettersEncountered = true;
            if (gapBetweenLetters > 0)
            {
                k++;
                gapsVector.push_back(gapBetweenLetters);
                gapBetweenLetters = 0;
            }
        }
    }
    sort(gapsVector.begin(), gapsVector.end());
    lli bestAnswer = k * l;
    for (auto i : gapsVector)
    {
        k--;
        l += i;
        bestAnswer = min(bestAnswer, k * l);
    }
    cout << bestAnswer << '\n';
}
int main()
{
    lli t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}