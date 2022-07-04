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
const ll INF = 1e18;
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
vl a;
struct ST{
    int n; vl st;
    ST(int n1){
        n = n1;
        st = vl(4 * n + 5, 0);
    }

    int left(int node) { return 2 * node; }
    int right(int node) { return 2 * node + 1; }

    void calc(int node){
        st[node] = max(st[left(node)], st[right(node)]); 
    }

    void update(int k, ll v, int tr, int tl = 1, int node = 1){
        if(tl == tr){
            st[node] += v;
            return;
        }
        int mid = (tl + tr) / 2;
        if(k >= tl && k <= mid){
            update(k, v, mid, tl, left(node));
        }
        else{
            update(k, v, tr, mid + 1, right(node));
        }
        calc(node);
    }

    ll query(int ql, int qr, int tr, int tl = 1, int node = 1){
        if(tl >= ql && tr <= qr){
            return st[node];
        }
        if(tr < ql || tl > qr){
            return 0;
        }
        int mid = (tl + tr) / 2;
        return max(query(ql, qr, mid, tl, left(node)), query(ql, qr, tr, mid + 1, right(node)));
    }

    ll bin_search(ll k){
        int l = 1, r = n;
        if(query(1, n, n) < k) return 0;
        while(l < r){
            int mid = (l + r) / 2;
            if(query(l, mid, n) >= k){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        update(r, -k, n);
        return r;
    }

};

void solve() {

    int n, m; cin >> n >> m;
    ST st(n);
    F0R(i, n){
        ll x; cin >> x;
        st.update(i + 1, x, n);
    }
    // cout << st.query(2, 4, n) << "\n";
    F0R(i, m){
        ll x; cin >> x;
        cout << st.bin_search(x) << " ";
    }

}

int main() {
    setIO("");
    int T = 1;
    // cin >> T;
    for (test = 1; test <= T; test++) solve();
    return 0;
}