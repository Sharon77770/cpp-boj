#include <bits/stdc++.h>

#define endl "\n"

#define FASTIO std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0)

#define GET(A,B) (A[B.first][B.second])

using namespace std;

using lld = long long int;
using iip = pair<int, int>;
using iiit = tuple<int, int, int>;
using iilt = tuple<int, int, lld>;
using lllt = tuple<lld, lld, lld>;
using llp = pair<lld, lld>;

int main() {
    FASTIO;

    deque<int> st;
    int N, n;

    cin >> N;

    while (N--) {
    	int cmd;

    	cin >> cmd;

    	switch (cmd) {
    	case 1:
    		cin >> n;
    		st.push_front(n);
    		break;

    	case 2:
    		cin >> n;
    		st.push_back(n);
    		break;

    	case 3:
    		if (st.empty()) cout << -1 << endl;
    		else { cout << st.front() << endl; st.pop_front(); }
    		break;

    	case 4:
    		if (st.empty()) cout << -1 << endl;
    		else { cout << st.back() << endl; st.pop_back(); }
    		break;

    	case 5:
    		cout << st.size() << endl;
    		break;

    	case 6:
    		cout << (int)st.empty() << endl;
    		break;

    	case 7:
    		if (st.empty()) cout << -1 << endl;
    		else cout << st.front() << endl;
    		break;

    	default:
    		if (st.empty()) cout << -1 << endl;
    		else cout << st.back() << endl;
    		break;
    	}
    }

    return 0;
}
