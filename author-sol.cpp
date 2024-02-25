#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, ll> cnt;

ll bin_sqrt(ll num) {
	ll l = 0, r = 5000000001;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (mid * mid <= num) {
			l = mid;
		} else {
			r = mid;
		}
	}
	return l;
}

ll get(ll b, ll c) {
	ll D = b * b - 4 * c;
	if (D < 0) {
		return 0;
	}
	ll x1 = (b - bin_sqrt(D)) / 2;
	ll x2 = (b + bin_sqrt(D)) / 2;
	if (x1 + x2 != b || x1 * x2 != c) {
		return 0;
	}
	if (x1 == x2) {
		return cnt[x1] * (cnt[x1] - 1) / 2;
	}
	return cnt[x1] * cnt[x2];
}

void test_case(int& tc) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		cnt[a]++;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		ll b, c;
		cin >> b >> c;
		cout << get(b, c) << " ";
	}
	cout << "\n";
	cnt.clear();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
