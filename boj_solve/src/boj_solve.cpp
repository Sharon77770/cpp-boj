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


int N, M;
lld arr[1000001];
lld seg[4000004];
lld lazy[4000004];

lld make(int low, int hi, int idx) {
    if (low == hi)
        return seg[idx] = arr[low];
    int mid = (low + hi) / 2;
    return seg[idx] = (make(low, mid, idx * 2) + make(mid + 1, hi, idx * 2 + 1));
}

void updateLazy(int low, int hi, int idx) {
    if (lazy[idx] == 0) return;

    seg[idx] += lazy[idx] * (hi - low + 1);
    lazy[idx * 2] += lazy[idx];
    lazy[idx * 2 + 1] += lazy[idx];
    lazy[idx] = 0;
}

lld update(int ilow, int ihi, lld n, int low, int hi, int idx) {
    updateLazy(low, hi, idx);

    if (low == ilow && hi == ihi) {
        lazy[idx * 2] += n;
        lazy[idx * 2 + 1] += n;
        return seg[idx] += n * (hi - low + 1);
    }

    int mid = (low + hi) / 2;

    if (ihi <= mid) return seg[idx] = update(ilow, ihi, n, low, mid, idx * 2);
    else if (mid < ilow) return seg[idx] = update(ilow, ihi, n, mid + 1, hi, idx * 2 + 1);
    return seg[idx] = update(ilow, mid, n, low, mid, idx * 2) + update(mid + 1, ihi, n, mid + 1, hi, idx * 2 + 1);
}


lld get(int i, int low, int hi, int idx) {
    updateLazy(low, hi, idx);
    if (hi == low) return seg[idx];
    int mid = (low + hi) / 2;
    if (i <= mid) return get(i, low, mid, idx * 2);
    else return get(i, mid + 1, hi, idx * 2 + 1);
}

int main() {
    FASTIO;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    make(1, N, 1);

    cin >> M;

    for (int i = 0; i < M; ++i) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int a, b;
            lld c;

            cin >> a >> b >> c;

            update(a, b, c, 1, N, 1);
        }
        else {
            int a;

            cin >> a;

            cout << get(a, 1, N, 1) << endl;
        }
    }

    return 0;
}
