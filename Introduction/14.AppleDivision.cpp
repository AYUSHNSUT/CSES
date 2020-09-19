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
ll diff = INT_MAX;
ll backtrack(vl &a,ll i, ll sum1, ll sum2)
{
  if(i == a.size())
  {
    if(abs(sum2 - sum1) < diff)
    {
      diff = abs(sum2 - sum1);
      return diff;
    }
    else
    {
      return diff;
    }
  }

  ll t1 , t2;
  t1 = backtrack(a,i+1,sum1 + a[i],sum2);
    t2 = backtrack(a,i+1,sum1 ,sum2+a[i]);

  return min(t1,t2);
}

void solve()
{
  ll n;
  cin >> n;
  vl a(n);
  ll sum1 = 0;
  ll sum2 = 0;
  ll ts = 0;
  REP(i,n)
  {
    cin >> a[i];
    ts+=a[i];
  }

  ll ans = backtrack(a,0,0,0);

  cout << ans << endl;
}
int main()
{

    std::ios::sync_with_stdio(false);
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
