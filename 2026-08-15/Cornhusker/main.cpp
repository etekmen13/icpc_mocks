#pragma region 
#include <bits/stdc++.h>

using namespace std;
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define PER(i,a,b) for(int i = a; i >= b; i--)
#define per(i,a,b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

const ll MOD = 1000000007;

ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m; }
ll mod_sub(ll a, ll b, ll m) { return ((a % m) - (b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }
ll mod_exp(ll a, ll e, ll M) { ll res = 1; while (e) { if (e & 1) res = (res * a) % M; a = (a * a) % M; e >>= 1; } return res; }

template<class T>
ostream& operator <<(ostream& o, const vector<T>& vec) {
    for(const auto& e : vec) {
        o << e << " ";
    }
    o << endl;
    return o;
}

#pragma endregion

void solve() {
   vector<pi> corn_ears(5, pi(0,0));

   for(int i = 0; i < 5; ++i) {
      auto &[a, l] = corn_ears[i];
      cin >> a >> l;
   }
   int ears_per_row, kwf;
   cin >> ears_per_row >> kwf;
   ll sum = 0;
   for(int i = 0; i < 5; ++i) {
    auto &[a,l] = corn_ears[i]; 
      sum += (ll)a * l;
   }
  ll avg = sum / 5;
  ll numer = (avg * ears_per_row);
  ll result = numer / (ll)kwf;
  cout << result << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // OPTIONAL FOR SOME CONTESTS
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}