#include <bits/stdc++.h>
using namespace std;
#define ll long long
class SGTree
{
  vector<ll> seg, lazy;

public:
  SGTree(ll n)
  {
    seg.resize(4 * n + 5, 0);
    lazy.resize(4 * n + 5, 0);
  };
  void build(ll ind, ll tl, ll tr, vector<ll> &a)
  {
    if (tl == tr)
    {
      seg[ind] = a[tl];
      return;
    }
    ll mid = (tl + tr) >> 1;
    build(2 * ind + 1, tl, mid, a);
    build(2 * ind + 2, mid + 1, tr, a);
    seg[ind] = lcm(seg[2 * ind + 1], seg[2 * ind + 2]);
  }

  ll query(ll ind, ll tl, ll tr, ll l, ll r)
  {
    if (l > tr || r < tl)
      return -1;
    if (tl >= l && tr <= r)
      return seg[ind];
    ll mid = (tl + tr) >> 1LL;
    ll left = query(2 * ind + 1, tl, mid, l, r);
    ll right = query(2 * ind + 2, mid + 1, tr, l, r);
    if (left == -1)
      return right;
    if (right == -1)
      return left;
    return lcm(left, right);
  }

  void UpdateNode(ll ind, ll tl, ll tr, ll index, ll value, vector<ll> &a)
  {
    if (tl == tr)
    {
      seg[ind] = value;
      a[tl] = value;
      return;
    }
    ll mid = (tl + tr) >> 1LL;
    if (index <= mid)
      UpdateNode(2 * ind + 1LL, tl, mid, index, value, a);
    else
      UpdateNode(2 * ind + 2LL, mid + 1, tr, index, value, a);
    seg[ind] = lcm(seg[2 * ind + 1], seg[2 * ind + 2]);
  }
};