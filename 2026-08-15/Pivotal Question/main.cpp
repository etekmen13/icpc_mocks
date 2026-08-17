#pragma region
#include <bits/stdc++.h>

using namespace std;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define PER(i, a, b) for (int i = a; i >= b; i--)
#define per(i, a, b) for (int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

const ll MOD = 1000000007;

ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m; }
ll mod_sub(ll a, ll b, ll m) { return ((a % m) - (b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }
ll mod_exp(ll a, ll e, ll M) {
  ll res = 1;
  while (e) {
    if (e & 1)
      res = (res * a) % M;
    a = (a * a) % M;
    e >>= 1;
  }
  return res;
}

template <class T> ostream &operator<<(ostream &o, const vector<T> &vec) {
  for (const auto &e : vec) {
    o << e << " ";
  }
  o << endl;
  return o;
}

#pragma endregion
constexpr int MAX_NUM = 1'000'001;
void solve() {
  int n;
  cin >> n;
  vi nums(n);
  for (auto &e : nums) {
    cin >> e;
  }
  vi prefix_max(n + 1), suffix_min(n + 1);
  prefix_max[0] = 0;
  suffix_min[n] = MAX_NUM;
  for (int i = 0; i < n; ++i) {
    prefix_max[i + 1] = max(prefix_max[i], nums[i]);
    suffix_min[n - i - 1] = min(suffix_min[n - i], nums[n - i - 1]);
  }

  vi pivots{};
  pivots.reserve(100);

  for (int i = 0; i < n; ++i) {
    if (nums[i] >= prefix_max[i] && nums[i] < suffix_min[i + 1]) {
      pivots.push_back(nums[i]);
    }
  }
  cout << pivots.size();
  if (pivots.size() == 0) {
    cout << '\n';
    return;
  }

  cout << ' ';
  size_t cap = min((size_t)100,pivots.size());
  for (size_t i = 0; i < cap; ++i) {
    cout << pivots[i] << (i < cap - 1 ? ' ' : '\n');
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  // OPTIONAL FOR SOME CONTESTS
  // cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}