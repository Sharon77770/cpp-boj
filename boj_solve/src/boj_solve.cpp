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

    stack<int> st;
    int N;

    cin >> N;

    while (N--) {
    	int cmd;

    	cin >> cmd;

    	switch (cmd) {
    	case 1:
    		int n;
    		cin >> n;
    		st.push(n);
    		break;

    	case 2:
    		if (st.empty()) cout << -1 << endl;
    		else { cout << st.top() << endl; st.pop(); }
    		break;

    	case 3:
    		cout << st.size() << endl;
    		break;

    	case 4:
    		cout << (int)st.empty() << endl;
    		break;

    	default:
    		if (st.empty()) cout << -1 << endl;
    		else cout << st.top() << endl;
    		break;
    	}
    }

    return 0;
}
