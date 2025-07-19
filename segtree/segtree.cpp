/*
Basic segment tree for sum and maxima queries
*/

#include <iostream>
using namespace std;

#define ll long long
#define MAXN (ll)(1e5)
#define inf (1LL << 60)
#define l(i) ((i) << 1)
#define r(i) (l(i) | 1)

struct Node {
    ll sm, mx;
    Node() {
        sm = 0, mx = -inf;
    }
    Node(ll nsm, ll nmx) {
        sm = nsm, mx = nmx;
    }
    Node combine(Node const& aux) const {
        return {sm + aux.sm, max(mx, aux.mx)};
    }
};

struct Segtree {
    Node st[4 * MAXN + 1];
    Segtree() {
        
    }
    void init(ll i, ll lb, ll rb) {
        if (lb == rb) {
            st[i] = {};
        }
        else {
            ll mb = (lb + rb) / 2;
            init(l(i), lb, mb);
            init(r(i), mb + 1, rb);
            st[i] = st[l(i)].combine(st[r(i)]);
        }
    }
    void update(ll i, ll lb, ll rb, ll p, ll v) {
        if (lb == rb) {
            st[i] = {v, v};
        }
        else {
            ll mb = (lb + rb) / 2;
            if (p <= mb) {
                update(l(i), lb, mb, p, v);
            }
            else {
                update(r(i), mb + 1, rb, p, v);
            }
            st[i] = st[l(i)].combine(st[r(i)]);
        }
    }
    Node query(ll i, ll lb, ll rb, ll lq, ll rq) {
        if (lq <= lb && rb <= rq) {
            return st[i];
        }
        else if (rb < lq || rq < lb) {
            return {};
        }
        else {
            ll mb = (lb + rb) / 2;
            return query(l(i), lb, mb, lq, rq).combine(query(r(i), mb + 1, rb, lq, rq));
        }
    }
};