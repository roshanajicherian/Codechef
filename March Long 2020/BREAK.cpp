#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t = 0, s = 0;
    cin >> t >> s;
    while (t--)
    {
        int n = 0;
        cin >> n;
        int A[3], B[3];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < n; i++)
            cin >> B[i];
        sort(A, A + n);
        sort(B, B + n);
        int cur = 0;
        bool flg = false;
        for (int i = 0; i < n; i++)
        {
            flg = false;
            if (A[i] < B[i])
                cur = B[i];
            for (int j = i + 1; j < n; j++)
            {
                if (cur == A[j])
                {
                    flg = true;
                    break;
                }
            }
        }
        if (!flg)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}