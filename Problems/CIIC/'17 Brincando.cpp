#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> p;
typedef long long ll;
typedef vector<ll> vll;
typedef unsigned long long ull;

#define F first 
#define S second 
#define PB push_back 
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define pmod 1000000007
#define MOD 1000000
#define INF 1000000000000000000
#define pi atan(1)*4

ull sum = 0;

vector<ull> din;

ull count(ull n, ull k) {
    if (n <= 1) {
        din[n] = 1;
        sum += 1;

        return 0;
    }
    if (n < k) {
        din[n] = sum;
        sum += sum;
        sum %= MOD;

        return din[n];
    }

    ull past = din[n % k];
    din[n % k] = sum;

    sum = (MOD + 2 * sum - past) % MOD;

    return din[n % k];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull k, n;

    cin >> k >> n;

    din.assign(k, -1);

    for (ull i = 0; i <= n; i++) {
        count(i, k);
    }

    cout << din[n % k] << endl;



    return 0;
}