#include <bits/stdc++.h>
using namespace std;
class SGTree
{
    vector<int> seg, lazy;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, 0);
    }
    // O(n)
    void build(int ind, int l, int r, int a[])
    {
        if (l == r)
        {
            seg[ind] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * ind + 1, l, mid, a);
        build(2 * ind + 2, mid + 1, r, a);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    // O(logn)
    int query(int ind, int low, int high, int l, int r)
    {
        // No overlap
        if (high < l || low > r)
            return INT_MAX;
        // complete OverLap
        if (low >= l && high <= r)
            return seg[ind];
        // partial overlap
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }
    // O(logn)
    void updateNode(int ind, int low, int high, int i, int val, int a[])
    {
        if (low == high)
        {
            seg[ind] = val;
            a[low] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid && i >= low)
            updateNode(2 * ind + 1, low, mid, i, val, a);
        else
            updateNode(2 * ind + 2, mid + 1, high, i, val, a);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    // O(Logn)
    void lazyRangeUpdate(int ind, int low, int high, int l, int r, int val)
    {
        // Updating the nodes
        if (lazy[ind] != 0)
        {
            seg[ind] += lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // No Overlap
        if (high < l || low > r)
            return;
        // Complete Overlap
        if (low >= l && high <= r)
        {
            seg[ind] += val;
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        // Partial OverLap
        int mid = (high + low) >> 1;
        lazyRangeUpdate(2 * ind + 1, low, mid, l, r, val);
        lazyRangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    // O(logn)
    int lazy_query(int ind, int low, int high, int l, int r)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (high < l || low > r)
            return INT_MAX;
        if (low >= l && high <= r)
            return seg[ind];
        int mid = (low + high) >> 1;
        int left = lazy_query(2 * ind + 1, low, mid, l, r);
        int right = lazy_query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }
};