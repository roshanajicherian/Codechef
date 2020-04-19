#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, w[mxN];

void solve() {
	//input
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> w[i];

	//find max
	int mx=0;
	for(int i=0; i<n; ++i)
		mx=max(w[i], mx);

	//find length of subarrays in S
	vector<int> v;
	for(int i=0, j=0; i<n; i=j) {
		if(w[i]==mx) {
			++j;
			continue;
		}
		for(; j<n&&w[j]^mx; ++j);
		v.push_back(j-i);
	}
	//first and last subarrays might be connected
	if(w[0]^mx&&w[n-1]^mx) {
		v[0]+=v.back();
		v.pop_back();
	}

	//calculate answer
	int ans=0;
	for(int vi : v)
		ans+=max(vi-n/2+1, 0);
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}