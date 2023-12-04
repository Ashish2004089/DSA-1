#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Segment tree for maximum in a range and number of times it occurs in range l,r
class SGTree
{
  vector<pair<ll, ll>> seg;

public:
  SGTree(ll n)
  {
    seg.resize(4 * n + 5, {0, 0});
  };

  void build(ll ind, ll tl, ll tr, vector<ll> &a)
  {
    if (tl == tr)
    {
      seg[ind] = {a[tl], 1LL};
      return;
    }
    ll mid = (tl + tr) >> 1;
    build(2 * ind + 1, tl, mid, a);
    build(2 * ind + 2, mid + 1, tr, a);
    seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
  }

  pair<ll, ll> query(ll ind, ll tl, ll tr, ll l, ll r)
  {
    if (l > tr || r < tl)
      return {-1e10, 0};
    if (tl >= l && tr <= r)
      return seg[ind];
    ll mid = (tl + tr) >> 1LL;
    pair<ll, ll> left = query(2 * ind + 1, tl, mid, l, r);
    pair<ll, ll> right = query(2 * ind + 2, mid + 1, tr, l, r);
    return combine(left, right);
  }

  void UpdateNode(ll ind, ll tl, ll tr, ll index, ll value, vector<ll> &a)
  {
    if (tl == tr)
    {
      seg[ind] = {value, 1};
      a[tl] = value;
      return;
    }
    ll mid = (tl + tr) >> 1LL;
    if (index <= mid)
      UpdateNode(2 * ind + 1LL, tl, mid, index, value, a);
    else
      UpdateNode(2 * ind + 2LL, mid + 1, tr, index, value, a);
    seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
  }

  pair<ll, ll> combine(pair<ll, ll> &a, pair<ll, ll> &b)
  {
    if (a.first > b.first)
      return a;
    if (b.first > a.first)
      return b;
    return {a.first, a.second + b.second};
  }
};