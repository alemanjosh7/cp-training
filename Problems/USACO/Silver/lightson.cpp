#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
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
#define yes cout << "Y" << "E" << "S\n";
#define no cout << "N" << "O\n";

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = ((b)-1); i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const ll MOD = 1e9 + 7;
const ll MX = 1e9;
const ll INF = 1e18;
const db PI = acos((db)-1);
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

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
char dbgq = '?';

/*

    +1 0
    +1 +1

    x y
    x-1, y
    x+1, y
    x, y + 1
    x, y - 1

*/
int n, m;

bool inRange(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= n) return 1;
    return 0;
}

map<pi, vector<pi>> mp;
map<pi, bool> vis;
map<pi, bool> lit;

void solve() {

    cin >> n >> m;
    F0R(i, m) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        mp[{x2, y2}].pb({ x1, y1 });
        lit[{x2, y2}] = 1;

    }
    int cnt = 0;
    queue<pi> q;
    q.push({ 1, 1 });

    lit[{1, 1}] = 1;
    while (!q.empty()) {
        pi u = q.front(); q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ++cnt;
        // cout << u.f << " " << u.s << "\n";
        if (inRange(u.f + 1, u.s)) {
            pi v = { u.f + 1, u.s };
            bool can = 0;
            each(x, mp[v]) {
                if (lit[x]) can = 1;
            }
            if (can) q.push({ u.f + 1, u.s });
        }
        if (inRange(u.f - 1, u.s)) {
            pi v = { u.f - 1, u.s };
            bool can = 0;
            each(x, mp[v]) {
                if (lit[x]) can = 1;
            }
            if (can) q.push({ u.f - 1, u.s });
        }
        if (inRange(u.f, u.s + 1)) {
            pi v = { u.f, u.s + 1 };
            bool can = 0;
            each(x, mp[v]) {
                if (lit[x]) can = 1;
            }
            if (can) q.push({ u.f, u.s + 1 });
        }
        if (inRange(u.f, u.s - 1)) {
            pi v = { u.f, u.s - 1 };
            bool can = 0;
            each(x, mp[v]) {
                if (lit[x]) can = 1;
            }
            if (can) q.push({ u.f, u.s - 1 });
        }

    }

    cout << cnt << "\n";

}

signed main() {
    setIO("lightson");
    int T = 1;
    // cin >> T;
    for (test = 1; test <= T; test++) solve();
}