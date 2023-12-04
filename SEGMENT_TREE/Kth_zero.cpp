#include <bits/stdc++.h>
using namespace std;
#define ll long long
class SGTree
{
    vector<ll> seg;

public:
    SGTree(ll n)
    {
        seg.resize(4 * n + 5, 0);
    };
    void build(ll ind, ll tl, ll tr, vector<ll> &a)
    {
        if (tl == tr)
        {
            seg[ind] = (a[tl] == 0);
            return;
        }
        ll mid = (tl + tr) >> 1LL;
        build(2LL * ind + 1LL, tl, mid, a);
        build(2LL * ind + 2LL, mid + 1LL, tr, a);
        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }

    ll query(ll ind, ll tl, ll tr, ll k)
    {
        if (k > seg[0])
            return -1;
        if (tl == tr)
        {
            return tl;
        }
        ll mid = (tl + tr) >> 1LL;
        if (seg[2 * ind + 1] >= k)
            return query(2 * ind + 1, tl, mid, k);
        else
            return query(2 * ind + 2, mid + 1, tr, k - seg[2 * ind + 1]);
    }

    void UpdateNode(ll ind, ll tl, ll tr, ll index, ll value, vector<ll> &a)
    {
        if (tl == tr)
        {
            seg[ind] = value == 0 ? 1 : 0;
            a[tl] = value;
            return;
        }
        ll mid = (tl + tr) >> 1LL;
        if (index <= mid)
            UpdateNode(2 * ind + 1LL, tl, mid, index, value, a);
        else
            UpdateNode(2 * ind + 2LL, mid + 1, tr, index, value, a);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};