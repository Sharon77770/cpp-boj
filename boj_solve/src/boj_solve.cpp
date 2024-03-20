#include <iostream>
#include <vector>

#define endl "\n"

#define FASTIO std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0)

using namespace std;

using lld = long long int;
using iip = pair<int, int>;
using iiit = tuple<int, int, int>;
using iilt = tuple<int, int, lld>;
using lllt = tuple<lld, lld, lld>;
using llp = pair<lld, lld>;

const int MAX_LEN = 600010;

lld seg[MAX_LEN];
lld lazy[MAX_LEN];
vector<int> nodeName;
vector<int> section;
vector<vector<int>> graph;
int M, N, root;

void renameNode(int cur, int& n) {
	nodeName[cur] = n++;
	for(auto& nxt : graph[cur])
		renameNode(nxt, n);

	section[cur] = n - 1;
}

void updateLazy(int low, int hi, int idx) {
	if(lazy[idx] == 0) return;

	seg[idx] += lazy[idx] * (hi - low + 1);
	lazy[idx * 2] += lazy[idx];
	lazy[idx * 2 + 1] += lazy[idx];
	lazy[idx] = 0;
}

lld updateSeg(int ilow, int ihi, lld w, int low, int hi, int idx) {
	updateLazy(low, hi, idx);

	if(ilow == low && ihi == hi) {
		lazy[idx * 2] += w;
		lazy[idx * 2 + 1] += w;
		return seg[idx] += w * (hi - low + 1);
	}

	int mid = (low + hi) / 2;

	if(ihi <= mid) return seg[idx] = updateSeg(ilow, ihi, w, low, mid, idx * 2);
	else if(ilow > mid) return seg[idx] = updateSeg(ilow, ihi, w, mid + 1, hi, idx * 2 + 1);
	return seg[idx] = updateSeg(ilow, mid, w, low, mid, idx * 2) +
			updateSeg(mid + 1, ihi, w, mid + 1, hi, idx * 2 + 1);
}

lld getData(int targ, int low, int hi, int idx) {
	updateLazy(low, hi, idx);

	if(low >= hi) return seg[idx];

	int mid = (low + hi) / 2;

	if(targ <= mid) return getData(targ, low, mid, idx * 2);
	else return getData(targ, mid + 1, hi, idx * 2 + 1);
}

int main() {
    FASTIO;

    cin >> N >> M;

    graph.resize(N + 1);
    section.resize(N + 1);
    nodeName.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
    	int parent;

    	cin >> parent;

    	if(parent != -1) graph[parent].push_back(i);
    }

    int cmd = 1;
    renameNode(1, cmd);

    while (M--) {
    	cin >> cmd;

    	if (cmd == 1) {
    		int i;
    		lld w;

    		cin >> i >> w;

    		updateSeg(nodeName[i], section[i], w, 1, N, 1);
    	}
    	else {
    		int i;

    		cin >> i;

    		cout << getData(nodeName[i], 1, N, 1) << endl;
    	}
    }

    return 0;
}
