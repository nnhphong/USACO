#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef complex<ld> cp;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<cp> vcp;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for( ll i = (l) ; i < (r) ; i++ )
#define forb(i,r,l) for( ll i = (r) ; i >= (l) ; i-- )
#define log2i(x) (32 - __builtin_clz((x)) - 1)
#define log2ll(x) (64 - __builtin_clzll((x)) - 1)
#define Pi 3.141592653589793
#define sz(x) (int)x.size()
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
  freopen("hayfeast.in", "r", stdin);
  freopen("hayfeast.out", "w", stdout);
  fastIO;

  ll n, m;
  cin >> n >> m;

  ll F[n], S[n];
  forw(i, 0, n) cin >> F[i] >> S[i];

  ll L = 0, f = 0, res = 1e9;
  multiset<ll, greater<ll>> ms;

  forw(R, 0, n) {
    f += F[R];
    ms.insert(S[R]);

    while (f - F[L] >= m) {
      f -= F[L];
      ms.erase(ms.find(S[L++]));
    }

    if (f >= m) res = min(res, *ms.begin());
  }
  cout << res << endl;
}
