#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for( ll i = (l) ; i < (r) ; i++ )
#define forb(i,r,l) for( ll i = (r) ; i >= (l) ; i-- )
#define sz(x) (int)x.size()
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define cntbit(x) __builtin_popcount(x)
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
/** ORDERED SET **/
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fkey order_of_key

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

const int N = 1005;
const ll inf = 1e9;

int dp[N][1010], n, m, c, moo[N];
vi adj[N];

void solve() {
  cin >> n >> m >> c;
  forw(i, 1, n+1) cin >> moo[i];
  forw(i, 0, m) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
  }

  forw(t, 0, 1001) forw(u, 1, n+1) dp[u][t] = -1;
  dp[1][0] = 0;

  ll ttl = 0, pos = -1;
  forw(t, 1, 1001) {
    forw(u, 1, n+1) {
      for (int v: adj[u]) {
        if (dp[u][t-1] >= 0)
          dp[v][t] = max(dp[v][t], dp[u][t-1] + moo[v]);
      }
    }

    ttl = max(ttl, dp[1][t] - 1ll * t * t * c);
  }
  cout << ttl << endl;
}

int main() {
  fastIO;
  freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);

  int tc = 1;
//  cin >> tc;
  while (tc--) {
    solve();
  }
}

/* stuff you should look for
    - int overflow, array bounds
    - special cases (n=1?)
    - do smth instead of do nothing and stay organized
    - WRITE STUFF DOWN
    - DONT JUST STICK ON ONE APPROACH
*/

