#include<bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
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
ll wrong[1000000];

void solve()
{
  ll n;
  cin >> n;

  if(n>=1)
  {
    cout << 0 << endl;
  }
  if(n>=2)
  {
    cout << 6 << endl;
  }
  if(n>=3)
  {
    cout << 28 << endl;
  }

  for(ll i = 4;i<=n;i++)
  {
    ll j = i*i;
    ll tot = j * (j-1);
    tot /= 2;
//    DEBUG(tot);
    wrong [i] = 2*3 + 12;
    wrong[i] -= 2;
  //  DEBUG(wrong[i]);
    if(i>4)
    {
      wrong[i] += 4* (2*i - 8);
    }
    wrong[i] += wrong[i-1];
  //  DEBUG(wrong[i]);
    tot = tot - wrong[i];
    cout << tot << endl;
  }
}
int main()
{

    std::ios::sync_with_stdio(false);
    int t = 1;
  //  cin >> t;
    wrong[1] = 1;
    wrong[2] = 0;
    wrong[3] = 8;
    while(t--)
      {
         solve();
      }


//fout.close();
//fin.close();
    return 0;
}
