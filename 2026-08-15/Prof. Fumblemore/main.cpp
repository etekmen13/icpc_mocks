#pragma region aliases
#include <bits/stdc++.h>
#ifdef DEBUG
#define dbg(msg)                                                               \
  do {                                                                         \
    cout << msg;                                                               \
  } while (0)
#else
#define dbg(msg)                                                               \
  do {                                                                         \
  } while (0)
#endif

using namespace std;
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

template <class T>
concept Range = ranges::range<T> && !same_as<remove_cvref_t<T>, string>;

template <class T> void pr(T &&);

template <class A, class B> void pr(const pair<A, B> &);

#pragma endregion

void fail() {
  cout << "INVALID" << endl;
  exit(0);
};
void solve() {
  string CST;
  cin >> CST;

  dbg(CST << endl);

  // assume n < m, CST(n) == CST(M) and first_pow2(n) > first_pow2(m)
  //  CS(n) does not flip sign, so CS(n) would have to be > CS(m) the entire
  //  time. thus n > m. contradiction.
  //  Thus if CST(n) == CST(M) and first_pow2(n) > first_pow2(m), then n > m.
  //  This allows me to greedily find the smallest pow2 satisfying the CST.
  if (CST.back() != 'O')
    fail();
  for (int i = 0; i < (int)CST.size(); ++i) {
    if (CST[i] != 'E' && CST[i] != 'O')
      fail();
    if (i + 1 < (int)CST.size() && CST[i] == 'O' && CST[i + 1] == 'O')
      fail();
  }
  for (int i = 4; i <= 47; ++i) {
    uint64_t cs_n = 1 << i;
    bool fail = false;
    for (auto it = CST.rbegin(); it != CST.rend(); ++it) {
      dbg(cs_n << " ");
      if (cs_n < 3) {
        dbg("FAIL\n");
        fail = true;
        break;
      }

      if (*it == 'O') {
        if ((cs_n - 1) % 3 != 0) {
          dbg("FAIL\n");
          fail = true;
          break;
        }
        cs_n = (cs_n - 1) / 3;
      }

      if (*it == 'E')
        cs_n *= 2;

      if (has_single_bit(cs_n)) {
        dbg("FAIL\n");
        fail = true;
        break;
      }
    }
    dbg("n = " << cs_n << endl);
    if (!fail) {
      cout << cs_n << '\n';
      return;
    }
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
