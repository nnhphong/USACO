#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using ii = pair<int, int>;
 
#define x first
#define y second
#define pb push_back
#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define getBit(x, i) ((x) >> (i) & 1)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
template<class X, class Y>
	bool minimize(X &x, const Y &y) {
	    X eps = 1e-9;
	    if (x > y + eps) {
	        x = y;
	        return true;
	    } else return false;
	}
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }

const int N = 1e5 + 7, M = 1e6 + 1, INF = 1e9 + 7;

struct Seg {
	int left, right;
} T[M];

int n, cnt[M];
ii p[N];

void build(int id, int l, int r) { // build with column 0
	if (l == r) {
		T[id].left = 0;
		T[id].right = cnt[l];
		return;
	}

	int mid = l + r >> 1, k = id << 1;
	build(k, l, mid);
	build(k | 1, mid + 1, r);
	T[id].left = T[k].left + T[k | 1].left;
	T[id].right = T[k].right + T[k | 1].right;
}

void update(int id, int l, int r, int p) { // update with column p
	if (l == r) {
		T[id].left += 1, T[id].right -= 1;
		return;
	}	

	int mid = l + r >> 1, k = id << 1;
	update(k, l, mid, p);
	update(k | 1, mid + 1, r, p);
	T[id].left = T[k].left + T[k | 1].left;
	T[id].right = T[k].right + T[k | 1].right;
}

/*
l1: top left
r1: top right
l2: bottom left
r2: bottom right
*/
int walk(int id, int l, int r, int l1, int r1, int l2, int r2) {
			
}

int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);

	build(1, 1, M - 1);
	for (int j = 2; j < M; j += 2) { // for each column	
		update(1, 1, M - 1, j);
		
	}	
}