#include <iostream>
#include <set>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#define ll long long
#define MAXN (ll)(1e5)
#define inf (1LL << 60)

struct Line {
    ll m, b;
    bool operator <(Line const& l) const {
        if (m == l.m) {
            return b > l.b;
        }
        return m > l.m;
    }
    bool operator >(Line const& l) const {
        if (m == l.m) {
            return b < l.b;
        }
        return m < l.m;
    }
    ll eval(ll x) {
        return m * x + b;
    }
};

struct DCHT {
    set<Line> ls;
    void insert(Line l) {

    }
    ll query(ll x) {
        return 0;
    }
};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}