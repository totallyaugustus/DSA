/*
Static unimodal convex hull for minima queries
*/

#include <iostream>
#include <deque>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#define ll long long
#define inf (1LL << 60)

struct Line {
    ll m, b;
    Line() {
        m = inf, b = inf;
    }
    Line(ll tm, ll tb) {
        m = tm, b = tb;
    }
    bool operator <(Line const& l) const {
        if (m == l.m) {
            return b < l.b;
        }
        return m < l.m;
    }
    bool operator >(Line const& l) const {
        if (m == l.m) {
            return b > l.b;
        }
        return m > l.m;
    }
    ll eval(ll x) {
        return m * x + b;
    }
    bool overlap(Line const& l, Line const& r) const {
        return (b - l.b) * (l.m - r.m) > (r.b - l.b) * (l.m - m);
    }
};

struct CHT {
    deque<Line> ls;
    CHT() {
        ls = {};
    }
    void insert(Line l) {
        Line t;
        while (ls.size() > 1) {
            t = ls.back();
            ls.pop_back();
            if (!t.overlap(ls.back(), l)) {
                ls.push_back(t);
                break;
            }
        }
        ls.push_back(l);
    }
    ll query(ll x) {
        Line t;
        while (ls.size() > 1) {
            t = ls.front();
            ls.pop_front();
            if (t.eval(x) < ls.front().eval(x)) {
                ls.push_front(t);
                break;
            }
        }
        return ls.front().eval(x);
    }
};