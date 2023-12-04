// SHREE GANESHAY NAMAH
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pow powl
#define sqrt sqrtl
#define log2 log2l
#define log10 log10l
#define F first
#define S second
#define si set<int>
#define pb push_back
#define ll long long
#define ld long double
#define INF LLONG_MAX
#define MINF LLONG_MIN
#define int long long
#define MOD 1000000007
#define pll pair<ll, ll>
#define vi vector<int>
#define om map<int, int>
#define eb emplace_back
#define SORT(v) sort(all(v))
#define REVERSE(v) reverse(all(v))
#define difinbits(a, b) setbits(a ^ b);
#define trailzero(x) __builtin_ctzll(x)
#define pt(x) cout << (x) << endl
#define ptw(x) cout << (x) << " "
#define setpri setprecision(12)
#define no cout << "no" << endl
#define No cout << "No" << endl
#define NO cout << "NO" << endl
#define yes cout << "yes" << endl
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, n) for (ll i = 1; i <= n; i++)
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define per(i, b, a) for (ll i = b; i >= a; i--)
#define all(v) v.begin(), v.end()
#define FIND(m, v) m.find(v) != m.end()
#define us unordered_set<int>
#define vvi vector<vector<int>>
#define MAXI(a) *max_element(all(a))
#define MINI(a) *min_element(all(a))
#define vpi vector<pair<int, int>>
#define ump unordered_map<int, int>
#define ub(a, x) upper_bound(all(a), x)
#define lb(a, x) lower_bound(all(a), x)
#define bs(a, x) binary_search(all(a), x)
#define AC(a, sum)    \
    for (auto it : a) \
        sum += it;
#define read(a)        \
    for (auto &it : a) \
        cin >> it;
#define setbits(x) __builtin_popcountll(x)
#define RSORT(v) sort(v.rbegin(), v.rend())
#define mkuniq(a) a.erase(unique(all(a)), a.end())
#define PI 3.1415926535897932384626433832795
#define to_upper(s) transform(all(s), s.begin(), ::toupper);
#define to_lower(s) transform(all(s), s.begin(), ::tolower);
#define readm(a)           \
    for (auto &it : a)     \
        for (auto &j : it) \
            cin >> j;
#define print(a)          \
    for (auto i : a)      \
        cout << i << " "; \
    cout << endl;
#define printm(m)    \
    for (auto i : m) \
        cout << i.first << " " << i.second << endl;
#define printmtx(v)           \
    for (auto i : v)          \
    {                         \
        for (auto j : i)      \
            cout << j << " "; \
        cout << "\n";         \
    }
#define CODE_BY_KARAN             \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define leftrotate(v, k) rotate(v.begin(), v.begin() + k, v.end());
#define rightrotate(v, k) rotate(v.begin(), v.begin() + v.size() - k, v.end())

/*-------------------------------------MATHEMATICAL FUNCTIONS--------------------------------------------*/
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }


/*-------------------------------------WRITE NEW FUNCTION FROM HERE--------------------------------------------*/
const int N = 22;
int dp[N][1 << N];
int f(int i, int mask, int n, vector<vector<int>> &a)
{
    if (i >= n)
        return 0;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    int ans = 1e9;
    for (int j = 0; j <= 20; j++)
        if ((mask >> j) & 1)
            ans = min(ans, f(i + 1, (mask ^ (1 << j)), n, a) + a[j][i]);
    return dp[i][mask] = ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    readm(a);
    int mask = powl(2, n) - 1;
    memset(dp, -1, sizeof(dp));
    cout << f(0, mask, n, a) << endl;
}
signed main()
{
    CODE_BY_KARAN;
    solve();
    return 0;
}