#include<bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define all(c) c.begin(),c.end()

#define M 1000000007


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define mp make_pair
#define pb push_back

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////
void solve()
{
  ll n , m;
  cin >> n >> m;

  vi a(n);

  REP(i,n)
  {
    cin >> a[i];
  }

  sort(all(a));
  ll low = 0, high = n-1;
  ll c = 0;

  while(low <= high)
  {
    ll cap = m;
    ll h = 0;
    while(low <= high && a[high] <= cap && h < 2)
    {
      cap = cap - a[high];
  //    DEBUG(a[high]);
      h++;
      high--;
    }
    while(low <= high && a[low] <= cap && h<2)
    {
      cap = cap - a[low];
      h++;
    //  DEBUG(a[low]);
      low++;;
    }

    c++;
  //  DEBUG(c);
  }
  // ll i = 0;
  //
  // while(i < n)
  // {
  //   ll cap = m;
  //   while(i < n && a[i] < cap)
  //   {
  //     cap-= a[i];
  //     i++;
  //   }
  //   c++;
  // }

  cout << c<< endl;
}

int main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
  //  cin >> t;

    while(t--)
      {
        solve();
      }




//fout.close();
//fin.close();
    return 0;
}
