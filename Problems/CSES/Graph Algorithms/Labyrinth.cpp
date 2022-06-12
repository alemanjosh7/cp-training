#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = ((b)-1); i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const ll MOD = 1e9 + 7;
const ll MX = 1e9;
const int INF = 1e9;
const db PI = acos((db)-1);
const int ddef[4]{ 1,0,-1,0 }, dataq[4]{ 0,1,0,-1 };
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void _print(char i) { cerr << i; }
void _print(string i) { cerr << i; }
void _print(float i) { cerr << i; }
void _print(int i) { cerr << i; }
void _print(double i) { cerr << i; }
void _print() { cerr << "\n"; };
template<typename x, typename y> void _print(pair<x, y>& t) { cerr << "{";_print(t.first);cerr << ", ";_print(t.second);cerr << "},"; }
template<typename x> void _print(x& t) { cerr << "{"; for (int i = 0;i < (int)t.size();i++) { _print(t[i]); if (i < (int)t.size() - 1) cerr << ", "; } cerr << "}"; }
template<typename x, typename... y> void _print(x a, y... b) { _print(a);if (sizeof...(b)) cerr << ", ";_print(b...); }
#define dbg(x...) cerr<<"["<<#x<<"] = [";_print(x);cerr<<"]\n";

int test;
const int MXN = 1e7;

void solve() {
    int n, m;
    cin >> n >> m;
    vi adj[MXN];
    string grid[n];
    int ori, fini;
    int cnt = 0;
    F0R(i, n) {
        str s; cin >> s;
        grid[i] = s;
        F0R(j, m) {
            if (grid[i][j] == 'A') {
                ori = cnt;
            }
            else if (grid[i][j] == 'B') {
                fini = cnt;
            }
            cnt++;
        }
    }
    cnt = 0;
    F0R(i, n) {
        F0R(j, m) {
            int v;
            cnt++;
            if (grid[i][j] == '#') continue;
            cnt--;
            if (i - 1 >= 0 && grid[i - 1][j] != '#') {
                // cout << i << " " << j << "A\n";
                v = cnt - m;
                adj[cnt].pb(v);
            }
            if (i + 1 < n && grid[i + 1][j] != '#') {
                // cout << i << " " << j << "B\n";
                v = cnt + m;
                adj[cnt].pb(v);
            }
            if (j - 1 >= 0 && grid[i][j - 1] != '#') {
                // cout << i << " " << j << "C\n";
                v = cnt - 1;
                adj[cnt].pb(v);
            }
            if (j + 1 < m && grid[i][j + 1] != '#') {
                // cout << i << " " << j << "D\n";
                v = cnt + 1;
                adj[cnt].pb(v);
            }
            cnt++;
        }
    }

    queue<int> q;
    vi dis(MXN, INF);
    vi prev(MXN, -1);
    bitset<MXN> vis;
    dis[ori] = 0;
    q.push(ori);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        each(v, adj[u]) {
            // cout << u << " -> " << v << "\n"; 
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                prev[v] = u;
                q.push(v);
            }
        }
    }

    if (dis[fini] == INF) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << dis[fini] << "\n";
    int idx = fini;
    string ans = "";
    while (idx != -1) {
        int aux = idx;
        // cout << idx << "\n";
        idx = prev[idx];
        if (idx == -1) break;
        if (aux + m == idx) ans += 'U';
        if (aux - m == idx) ans += 'D';
        if (aux - 1 == idx) ans += 'R';
        if (aux + 1 == idx) ans += 'L';
    }
    reverse(all(ans));
    F0R(i, dis[fini]) {
        cout << ans[i];
    }
    cout << "\n";
}

int main() {
    setIO("");
    int T = 1;
    // cin >> T;
    for (test = 1; test <= T; test++) solve();
    return 0;
}