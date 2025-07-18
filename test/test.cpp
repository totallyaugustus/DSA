/*
Dynamic convex hull for minima queries
*/

#include <iostream>
#include <set>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#define ll long long
#define inf (1LL << 60)

struct Line {
    ll rb, m, b;
    bool operator <(Line const& l) const {
        
    }
};

struct DCHT {
    set<Line> ls;
    void insert(Line l) {

    }
    ll query(ll x) {
        
    }
};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    return 0;
}