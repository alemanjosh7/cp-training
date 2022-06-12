#include "dna.h"
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
const int MXN = 1e5 + 1;
str s, t;
bitset<MXN> vis;
int prefS[MXN][3];
int prefT[MXN][3];

int alfa[MXN][6];
int omega[MXN][3];

void init(std::string a, std::string b) {
    F0R(i, sz(a)) {
        prefS[i + 1][0] = prefS[i][0] + (a[i] == 'A');
        prefS[i + 1][1] = prefS[i][1] + (a[i] == 'T');
        prefS[i + 1][2] = prefS[i][2] + (a[i] == 'C');

        prefT[i + 1][0] = prefT[i][0] + (b[i] == 'A');
        prefT[i + 1][1] = prefT[i][1] + (b[i] == 'T');
        prefT[i + 1][2] = prefT[i][2] + (b[i] == 'C');

        alfa[i + 1][0] = alfa[i][0] + (a[i] == 'A' && b[i] == 'T');
        alfa[i + 1][1] = alfa[i][1] + (a[i] == 'T' && b[i] == 'A');

        alfa[i + 1][2] = alfa[i][2] + (a[i] == 'A' && b[i] == 'C');
        alfa[i + 1][3] = alfa[i][3] + (a[i] == 'C' && b[i] == 'A');

        alfa[i + 1][4] = alfa[i][4] + (a[i] == 'C' && b[i] == 'T');
        alfa[i + 1][5] = alfa[i][5] + (a[i] == 'T' && b[i] == 'C');

        omega[i + 1][0] = omega[i][0] + (a[i] == 'A' && b[i] == 'A');
        omega[i + 1][1] = omega[i][1] + (a[i] == 'T' && b[i] == 'T');
        omega[i + 1][2] = omega[i][2] + (a[i] == 'C' && b[i] == 'C');

    }
    s = a;
    t = b;
}

int get_distance(int x, int y) {
    if ((prefS[y + 1][0] - prefS[x][0]) != (prefT[y + 1][0] - prefT[x][0]) ||
        (prefS[y + 1][1] - prefS[x][1]) != (prefT[y + 1][1] - prefT[x][1]) ||
        (prefS[y + 1][2] - prefS[x][2]) != (prefT[y + 1][2] - prefT[x][2])) {
        return -1;
    }

    int iguales = omega[y + 1][0] - omega[x][0] + omega[y + 1][1] - omega[x][1] + omega[y + 1][2] - omega[x][2];
    int inverso = min(alfa[y + 1][0] - alfa[x][0], alfa[y + 1][1] - alfa[x][1]) + min(alfa[y + 1][2] - alfa[x][2], alfa[y + 1][3] - alfa[x][3]) + min(alfa[y + 1][4] - alfa[x][4], alfa[y + 1][5] - alfa[x][5]);
    int restante = (y - x + 1) - inverso * 2 - iguales;
    if (iguales == y - x + 1) return 0;

    return restante + inverso - (restante / 3);
}