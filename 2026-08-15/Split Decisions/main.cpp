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

unordered_map<string, int> differences(vector<string> &words) {
  unordered_map<string, int> diffs;
  diffs.reserve(words.size() * (words.size() - 1) / 2 + 1);
  for (size_t i = 0; i < words.size(); ++i) {
    for (size_t j = i + 1; j < words.size(); ++j) {
      if (words[i].size() != words[j].size())
        continue;
      const auto &a = words[i];
      const auto &b = words[j];
      string diff(a.size() + 2, '\0');
      diff[0] = '\0';
      diff[a.size() + 1] = '\0';
      transform(a.begin(), a.end(), b.begin(), diff.begin() + 1,
                [](char x, char y) {
                  return static_cast<unsigned char>(x) -
                         static_cast<unsigned char>(y);
                });

      auto nonzero = [](char c) { return c != '\0'; };

      bool two_diffs = count_if(diff.begin(), diff.end(), nonzero) == 2;
      bool diffs_adjacent =
          adjacent_find(diff.begin(), diff.end(), [&](char x, char y) {
            return nonzero(x) && nonzero(y);
          }) != diff.end();

      if (two_diffs && diffs_adjacent) {
#ifdef DEBUG
        cout << a << " | " << b << endl;
#endif
        string ma(a.size(), '0'), mb(a.size(), '0');

        transform(a.begin(), a.end(), diff.begin() + 1, ma.begin(),
                  [](char c, char m) { return m ? c : '0'; });

        transform(b.begin(), b.end(), diff.begin() + 1, mb.begin(),
                  [](char c, char m) { return m ? c : '0'; });

        if (ma > mb)
          swap(ma, mb);

        diffs[ma + "|" + mb]++;
#ifdef DEBUG
        cout << ma + "|" + mb << endl;
#endif
      }
    }
  }
  return diffs;
}
void solve() {
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; ++i) {
    cin >> words[i];
  }

  auto diffs = differences(words);
#ifdef DEBUG
  for (auto &kv : diffs) {
    auto &[k, v] = kv;
    cout << k << ":\t" << v << endl;
  }
#endif
  auto num_uniq = count_if(diffs.begin(), diffs.end(), [](auto &kv) {
    auto &[k, v] = kv;
    return v == 1;
  });
  cout << num_uniq << '\n';
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
