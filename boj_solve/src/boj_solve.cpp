#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"

using namespace std;

using lld = long long int;

map<string, string> dp;

string getParent(map<string, string>& parent, string cur) {
	if(cur == parent[cur] || parent[cur] == "") return cur;
	if(dp[cur] != "") return dp[cur] = getParent(parent, dp[cur]);
	return dp[cur] = getParent(parent, parent[cur]);
}

int link_set(map<string, string>& parent, map<string, int>& childCnt, string a, string b) {
	auto ap = getParent(parent, a), bp = getParent(parent, b);

	if(bp == ap) return childCnt[ap];

	if(a < b) {
		parent[bp] = ap;
		return childCnt[ap] += childCnt[bp];
	}
	else {
		parent[ap] = bp;
		return childCnt[bp] += childCnt[ap];
	}
}

int main() {
	FASTIO;

	int T;

	cin >> T;

	while(T--) {
		int F;
		map<string, string> parent;
		map<string, int> childCnt;
		dp.clear();

		cin >> F;

		while(F--) {
			string s1, s2;

			cin >> s1 >> s2;

			if(childCnt[s1] == 0){
				childCnt[s1] = 1;
				parent[s1] = s1;
			}
			if(childCnt[s2] == 0) {
				childCnt[s2] = 1;
				parent[s2] = s2;
			}

			cout << link_set(parent, childCnt, s1, s2) << endl;
		}
	}

	return 0;
}
