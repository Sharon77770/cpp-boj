#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"

using namespace std;
using idp = pair<int, double>;
using ddp = pair<double, double>;

vector<vector<idp>> edges;
vector<ddp> volts;
vector<bool> visi;

class Func {
public:
	bool operator() (idp& a, idp& b) { return a.second > b.second; }
};

inline double getDis(ddp& a, ddp& b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
	FASTIO;

	int N;

	cin >> N;

	volts.resize(N);
	visi.resize(N, false);
	edges.resize(N);

	for(int i = 0; i < N; ++i) {
		cin >> volts[i].first >> volts[i].second;

		for(int j = 0; j < i; ++j) {
			edges[i].push_back({ j, getDis(volts[i], volts[j])});
			edges[j].push_back({ i, getDis(volts[i], volts[j])});
		}
	}

	double ans = 0;
	priority_queue<idp, vector<idp>, Func> pq;
	pq.push({0, 0});

	for(int cnt = 0; cnt < N; ++cnt) {
		auto [cur, len] = pq.top();
		pq.pop();

		if(visi[cur]) { cnt--; continue; }

		visi[cur] = true;
		ans += len;

		for(auto& [n, l] : edges[cur]) {
			if(visi[n]) continue;
			pq.push({ n, l });
		}
	}

	cout.precision(2);
	cout << fixed;

	cout << ans;

	return 0;
}
