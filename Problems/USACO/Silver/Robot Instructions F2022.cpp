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

void solve() {

	int n;
	ll x, y; cin >> n >> x >> y;
	int m1 = n / 2;
	int m2 = n - m1;
	pair<ll, ll> a[m1], b[m2];
	// vector<pair<ll, ll>> a(m1), b(m2); // Podrian ser arreglos?
	F0R(i, m1) {
		ll X, Y; cin >> X >> Y;
		a[i] = { X, Y };
	}
	F0R(i, m2) {
		ll X, Y; cin >> X >> Y;
		b[i] = { X, Y };
	}
	pair<pair<ll, ll>, int> primero[(1 << m1)];
	pair<pair<ll, ll>, int> segundo[(1 << m2)];
	pair<ll, ll> sum1[(1 << m1)];
	pair<ll, ll> sum2[(1 << m2)];
	for (int i = 0; i < (1 << m1); i++) {
		pair<ll, ll> sum = { 0, 0 };
		int cnt = 0;
		for (int j = 0; j < m1; j++) {
			if (i & (1 << j)) {
				sum.f += a[j].f;
				sum.s += a[j].s;
				cnt++;
			}
		}
		primero[i] = { sum, cnt };
	}
	for (int i = 0; i < (1 << m2); i++) {
		pair<ll, ll> sum = { 0, 0 };
		int cnt = 0;
		for (int j = 0; j < m2; j++) {
			if (i & (1 << j)) {
				sum.f += b[j].f;
				sum.s += b[j].s;
				cnt++;
			}
		}
		segundo[i] = { sum, cnt };
	}

	sort(primero, primero + m1);
	sort(segundo, segundo + m2);
	int pasos1[(1 << m1)];
	int pasos2[(1 << m2)];
	int idx_1 = 0;
	each(s1, primero) {
		sum1[idx_1] = s1.f;
		pasos1[idx_1++] = s1.s;

	}
	idx_1 = 0;
	each(s2, segundo) {
		sum2[idx_1] = s2.f;
		pasos2[idx_1++] = s2.s;
	}
	int ans[n + 1] = { 0 };
	int idx = 0;
	each(s1, sum1) {
		pair<ll, ll> temp = { x - s1.f, y - s1.s };
		int l = lower_bound(sum2, sum2 + (1 << m2), temp) - sum2;
		int r = upper_bound(sum2, sum2 + (1 << m2), temp) - sum2;
		for (int j = l; j < r + 1; j++) {
			if (s1.f + sum2[j].f != x || s1.s + sum2[j].s != y) continue;
			ans[pasos1[idx] + pasos2[j]]++;
		}
		idx++;
	}

	FOR(i, 1, n + 1) cout << ans[i] << "\n";
}

int main() {
	setIO("");
	int T = 1;
	// cin >> T;
	for (test = 1; test <= T; test++) solve();
	return 0;
}