#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n, k;
int nums[200005];
bool visited[200005];

void solve(int test)
{
    vector<pair<int, int>> doub;
    vector<tuple<int, int, int>> answer;

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        visited[i] = false;
    }
    for (int i = 1; i <= n; ++i)
        if (!visited[i])
        {
            vector<int> cycle;
            int j = i;
            while (!visited[j])
            {
                visited[j] = true;
                cycle.push_back(j);
                j = nums[j];
            }
            while (cycle.size() > 2)
            {
                // x -> y -> z -> x
                int z = cycle.back();
                cycle.pop_back();
                int y = cycle.back();
                cycle.pop_back();
                int x = cycle.back();
                if (cycle.size() == 1)
                    cycle.pop_back();
                answer.push_back(tie(x, y, z));
                --k;
            }
            if (cycle.size() == 2)
            {
                doub.push_back(make_pair(cycle[0], cycle[1]));
            }
        }
    while (doub.size() > 1)
    {
        // a -> b -> a,
        // c -> d -> c
        pair<int, int> one = doub.back();
        doub.pop_back();
        pair<int, int> two = doub.back();
        doub.pop_back();
        // b -> c -> d
        // a -> b -> c
        answer.push_back(tie(one.second, two.first, two.second));
        answer.push_back(tie(one.first, one.second, two.first));
        k -= 2;
    }
    if (!doub.empty())
    {
        k = -1;
    }
    if (k < 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << answer.size() << endl;
        for (int i = 0; i < answer.size(); ++i)
        {
            cout << get<0>(answer[i]) << " "
                 << get<1>(answer[i]) << " "
                 << get<2>(answer[i]) << endl;
        }
    }
    return;
}

int main()
{
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; ++i)
    {
        solve(i);
    }
    return 0;
}
