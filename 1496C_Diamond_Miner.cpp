//Problem Link -: https://codeforces.com/contest/1496/problem/C

//Solution
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define mod 1000000007
int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}
bool compare(int a, int b) {
	return a > b;
}
int32_t main() {
	fio;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>>x_axis, y_axis;
		for (int i = 0; i < 2 * n; i++) {
			int a, b;
			cin >> a >> b;
			if (a == 0) {
				y_axis.push_back({a, abs(b)});
			}
			else {
				x_axis.push_back({abs(a), b});
			}

		}
		sort(x_axis.begin(), x_axis.end());
		sort(y_axis.begin(), y_axis.end());
		double ans = 0.00;
		for (int i = 0; i < n; i++) {
			ans += double(sqrt(double(x_axis[i][0] * x_axis[i][0]) + double(y_axis[i][1] * y_axis[i][1])));
		}
		cout << fixed << setprecision(10) << ans << endl;
	}
	return 0;
}