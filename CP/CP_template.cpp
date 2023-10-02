#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
  os << '{';
  string sep;
  for (const T &x : v)
    os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
  cerr << ' ' << H;
  dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

map<int, int> m;

ll solve(ll n, ll temp, ll indexStart)
{
  if (m[n] == 1)
    return 0;
  if (n == 1)
    return 1;

  // cout << n << " " << temp << " " << indexStart << '\n';

  if (indexStart == 0)
    return n + solve(n - temp + 1, temp - 1, 0);

  ll end = temp * (temp + 1) / 2;
  ll start = temp * (temp - 1) / 2 + 1;

  if (n == end)
    return n + solve(n - temp, temp - 1, n - start);

  ll duplicate = start - (temp - 1) - (temp - 2) + indexStart - 1;
  if (duplicate <= 0)
    duplicate = 0;
  else
    m[duplicate] = 1;

  return n + solve(start - temp + 1 + indexStart - 1, temp - 1, indexStart - 1) + solve(start - temp + 1 + indexStart, temp - 1, indexStart) + duplicate;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++)
  {
    ll n;
    cin >> n;
    ll temp = round(sqrt(2 * n));
    ll start = temp * (temp - 1) / 2 + 1;
    cout << solve(n, temp, n - start) << endl;
    m.clear();
  }
}