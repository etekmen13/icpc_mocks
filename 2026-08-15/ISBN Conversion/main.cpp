#include <algorithm>
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

#pragma endregion

void validate_hyphens(vector<string> &isbn) {
  for (auto &s : isbn) {
    vi hyphens;
    hyphens.reserve(13);

    if (s.front() == '-' || s.back() == '-' ||
        adjacent_find(s.begin(), s.end(), [](char a, char b) {
          return a == '-' && a == b;
        }) != s.end()) {

      s = "invalid";
      continue;
    }
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == '-') {
        hyphens.push_back(i);
      }
    }

    if (hyphens.size() > 3) {

      s = "invalid";
      continue;
    }

    if (hyphens.size() == 3 && hyphens.back() != (int)s.size() - 2) {
      s = "invalid";
      continue;
    }
  }
}

vector<vi> parse_digits(const vector<string> &isbn) {

  vector<vi> digits(isbn.size());
  for (size_t i = 0; i < isbn.size(); ++i) {
    auto &s = isbn[i];
    if (s == "")
      continue;
    vi d;
    d.reserve(s.size());
    for (const auto &c : s) {
      if (c >= '0' && c <= '9')
        d.pb(c - '0');
      else if (c == 'X')
        d.pb(10);
    }
    if (d.size() != 10)
      continue;
    digits[i] = std::move(d);
  }
  return digits;
}

vl checksum_10(const vector<vi> &digits) {
  vl checksums(digits.size());

  for (size_t i{}; i < digits.size(); ++i) {
    auto &nums = digits[i];
    ll &checksum = checksums[i];
    if (nums.empty()) {
      checksum = -1ll;
      continue;
    }
    for (int m = 0; m < 10; ++m) {
      checksum += (10 - m) * nums[m];
    }
  }
  return checksums;
}

void validate_checksum_10(const vl &checksums, vector<string> &isbn) {
  assert(checksums.size() == isbn.size());
  for (size_t i{}; i < isbn.size(); ++i) {
    auto &cs = checksums[i];
    if (cs == -1ll) {
      isbn[i] = "invalid";
      continue;
    }
    if (cs % 11 != 0) {
      isbn[i] = "invalid";
      continue;
    }
  }
}

vl checksum_13(const vector<vi> digits) {

  vl checksums(digits.size());

  for (size_t i{}; i < digits.size(); ++i) {
    auto &nums = digits[i];
    ll &checksum = checksums[i];
    if (nums.empty()) {
      checksum = -1ll;
      continue;
    }
    checksum += 9 + 3 * 7 + 8;
    for (int m{}; m < 9; ++m) {
      checksum += (m % 2 == 0 ? 3 : 1) * nums[m];
    }
    dbg("pre-checksum: " << checksum << endl);
    checksum = mod_sub(10, checksum, 10);
  }
  return checksums;
}
void convert_isbn13(const vl &checksums, vector<string> &isbn) {
  assert(checksums.size() == isbn.size());
  for (size_t i{}; i < isbn.size(); ++i) {
    if (isbn[i] == "invalid")
      continue;
    isbn[i] = "978-" + isbn[i];
    isbn[i].back() = static_cast<char>('0' + checksums[i]);
  }
}
void validate_X(vector<string> &isbn) {
  for (auto &s : isbn) {
    auto pos = s.find('X');
    if (pos != string::npos && pos != s.size() - 1)
      s = "invalid";
  }
}
void solve() {

  int t;
  cin >> t;
  vector<string> isbn(t);
  for (int i = 0; i < t; ++i) {
    isbn[i].reserve(20);
    cin >> isbn[i];
  }
  dbg(isbn << endl);
  validate_hyphens(isbn);
  dbg(isbn << endl);
  validate_X(isbn);
  auto digits = parse_digits(isbn);

  dbg(digits << endl);

  auto checksums_10 = checksum_10(digits);

  dbg("checksum_10: " << checksums_10 << endl);
  dbg("====\n");
  dbg(isbn << endl);
  validate_checksum_10(checksums_10, isbn);
  dbg(isbn << endl);

  auto checksums_13 = checksum_13(digits);
  dbg(checksums_13 << endl);
  dbg(isbn << endl);
  convert_isbn13(checksums_13, isbn);
  for (auto &s : isbn) {
    cout << s << '\n';
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
