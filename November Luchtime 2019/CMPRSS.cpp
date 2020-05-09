#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n = 0;
    cin >> n;
    int A[n];
    string result, tempString;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int i = 0;
    while (i < n)
    {
        int start = A[i], end = 0;
        int count = 0;
        tempString = "";
        int j = i;
        while (j < n)
        {
            tempString += "," + to_string(A[j]);
            if (j < n - 1 && A[j] + 1 == A[j + 1])
            {
                count++;
                end = A[j + 1];
            }
            else
            {
                i = j + 1;
                break;
            }
            j++;
        }
        if (count >= 2)
            result += "," + to_string(start) + "..." + to_string(end);
        else
            result += tempString;
    }
    if (result[0] == ',')
        result = result.substr(1, result.length());
    if (result[result.length()] == ',')
        result = result.substr(0, result.length() - 1);
    cout << result << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}