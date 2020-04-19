#include <bits/stdc++.h>
using namespace std;
#define mxN int(1e5)
int ql[mxN], qr[mxN], qy[mxN], ft[mxN];
struct Event
{
    int cord, stat, pos;
};
void update(int index, int val, int n)
{
    int res = 0;
    while (index <= n)
    {
        res += val;
        index += index & (-index);
    }
}
void query(int index, int val, int n)
{
    index -= index & (-index);
}
void solve()
{
    int n = 0, q = 0;
    cin >> n >> q;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        A.push_back(temp);
        for (int i = 0; i < q; ++i)
            cin >> ql[i] >> qr[i] >> qy[i], --ql[i], --qr[i];
        vector<Event> ve;
        for (int i = 0; i < n - 1; i++)
        {
            ve.push_back({min(A[i], A[i + 1]), 1, i});
            ve.push_back({max(A[i], A[i + 1]), 3, i});
        }
        for (int i = 0; i < q; i++)
            ve.push_back({qy[i], 2, i});
        sort(ve.begin(), ve.end()); //sort function sorts acording to the first constrain of the strcuture
        for (Event e : ve)
        {
            if (e.stat == 1)
            {
            }
            else if (e.stat = 2)
            {
            }
            else
            {
            }
        }
    }
}
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
}
