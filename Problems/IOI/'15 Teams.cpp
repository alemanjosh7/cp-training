#include <teams.h>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) bg(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = ((b)-1); i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

int n;
vector<pi> alfa;

bool cmp(const pi& x, const pi& y) {
    return x.s < y.s;
}

void init(int N, int A[], int B[]) {
    n = N;
    alfa.resize(n);
    F0R(i, n) {
        alfa[i].f = A[i];
    }
    F0R(i, n) {
        alfa[i].s = B[i];
    }

    sort(alfa.begin(), alfa.begin() + n, cmp);

    //     F0R(i, n){
    //         cout << alfa[i].f << " ";
    //     }
    //     cout << "\n";
    //     F0R(i, n){
    //         cout << alfa[i].s << " ";
    //     }
    //     cout << "\n";
}

int can(int M, int K[]) {
    multiset<int> k;
    sort(K, K + M);
    F0R(i, M) {
        F0R(j, K[i]) {
            k.insert(K[i]);
        }
    }

    // for(auto it = k.begin(); it != k.end(); ++it){
    //     cout << *it << " ";
    // }

    // cout << "\n";

    F0R(i, n) {
        auto it = k.lower_bound(alfa[i].f);
        if (it == k.end()) continue;
        // cout << alfa[i].f << " " << alfa[i].s << " " << *it << "\n";

        if (alfa[i].f <= (*it) && (*it) <= alfa[i].s) {
            k.erase(it);
        }
    }


    return sz(k) == 0;

}