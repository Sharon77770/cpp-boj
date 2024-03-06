#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>

#define endl "\n"

using namespace std;

using lld = long long int;

int dp[2001], dp2[2001];

class Func {
public:
	bool operator() (int& a, int& b) { return dp[a] > dp[b]; }
};

class Func2 {
public:
	bool operator() (int& a, int& b) { return dp2[a] > dp2[b]; }
};

void dijk(vector<vector<int>>& graph, int st) {
	priority_queue<int, vector<int>, Func> pq;
	memset(dp, -1, sizeof(dp));

	dp[st] = 0;
	pq.push(st);

	while(!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		for(int nxt = 0; nxt < graph.size(); ++nxt) {
			if(graph[cur][nxt] == 0) continue;

			if(dp[nxt] == -1) {
				dp[nxt] = dp[cur] + graph[cur][nxt];
				pq.push(nxt);
			}
			else if(dp[nxt] > dp[cur] + graph[cur][nxt]){
				dp[nxt] = dp[cur] + graph[cur][nxt];
				pq.push(nxt);
			}
		}
	}
}

void dijk2(vector<vector<int>>& graph, int st) {
	priority_queue<int, vector<int>, Func2> pq;
	memset(dp2, -1, sizeof(dp2));

	dp2[st] = 0;
	pq.push(st);

	while(!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		for(int nxt = 0; nxt < graph.size(); ++nxt) {
			if(graph[cur][nxt] == 0) continue;

			if(dp2[nxt] == -1) {
				dp2[nxt] = dp2[cur] + graph[cur][nxt];
				pq.push(nxt);
			}
			else if(dp2[nxt] > dp2[cur] + graph[cur][nxt]){
				dp2[nxt] = dp2[cur] + graph[cur][nxt];
				pq.push(nxt);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;

	cin >> T;

	while(T--) {
		vector<vector<int>> graph;
		vector<int> arr;
		int N, M, T;
		int S, G, H;

		cin >> N >> M >> T;
		cin >> S >> G >> H;

		graph.resize(N + 1, vector<int>(N + 1));
		arr.resize(T);

		while(M--) {
			int a, b, c;

			cin >> a >> b >> c;

			graph[a][b] = c;
			graph[b][a] = c;
		}

		for(auto& i : arr)
			cin >> i;

		dijk2(graph, S);

		int SG = dp2[G] + graph[G][H], SH = dp2[H] + graph[G][H];
		map<int, bool> ans;

		if(SG != -1) {
			dijk(graph, H);

			for(auto& e : arr) {
				if(dp[e] != -1) {
					if(SG + dp[e] == dp2[e])
						ans[e] = true;
				}
			}
		}

		if(SH != -1) {
			dijk(graph, G);

			for(auto& e : arr){
				if(dp[e] != -1) {
					if(SH + dp[e] == dp2[e])
						ans[e] = true;
				}
			}
		}

		for(const auto& pib : ans) {
			cout << pib.first << " ";
		}

		cout << endl;
	}

	return 0;
}
