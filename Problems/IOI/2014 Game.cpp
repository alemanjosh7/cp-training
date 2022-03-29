#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT > int lwb(V<T>& a, const T& b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T>& a, const T& b) { return int(ub(all(a), b) - bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = ((b)-1); i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

// const int MOD = 1e9+7; // 998244353;
const ll M = 1e9 + 7;
const ll MX = 1e9;
const ll LINF = 1e18;
const db PI = acos((db)-1);
const int ddef[4]{ 1,0,-1,0 }, dataq[4]{ 0,1,0,-1 }; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
    return x == 0 ? 0 : 31 - __builtin_clz(x);
} // floor(log2(x)) 
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down

tcT > bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0;
} // set a = min(a,b)
tcT > bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
} // set a = max(a,b)

const int MXN = 1500;
int mat[MXN][MXN];
int N;
struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        F0R(i, N) {
            mat[x][i] += mat[y][i];
            mat[i][x] += mat[y][i];
        }
        return true;
    }
};

DSU D(MXN);

void initialize(int n) {
    N = n;
}

int hasEdge(int u, int v) {
    u = D.get(u), v = D.get(v);
    if (u == v) return 1;
    if (mat[u][v] < D.size(v) * D.size(u) - 1) {
        mat[u][v]++;
        mat[v][u]++;
        return 0;
    }
    D.unite(u, v);
    return 1;
}