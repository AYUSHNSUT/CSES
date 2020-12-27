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
int dp[1000001];
int findMinCoins(vi &a, int total){

  if(total == 0 )
  {
    return 0;
  }

  if(total < 0)
  {
    return INT_MAX - 1;
  }
  if(dp[total] != -1)
  {
    return dp[total];
  }

  int tans = INT_MAX - 1;

  for(int i = 0;i<a.size();i++)
  {
    tans = min(tans , findMinCoins(a,total - a[i]) + 1);
  }
  dp[total] = tans;
  return dp[total];
}

void solve()
{
  int n, total;
  cin >> n >> total;

  memset(dp, -1, sizeof(dp));
  dp[0] = 0;

  vi a(n);
  REP(i,n)
  {
    cin >> a[i];
  }

  for(int i = 0; i< n;i++ )
  {
    dp[a[i]] = 1;
  }

  int ans = findMinCoins(a, total);

  if(ans >= INT_MAX-1)
  {
    ans = -1;
  }

  cout <<  ans << endl;
}

int main()
{

    std::ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;

    while(t--)
      {
        solve();
      }




//fout.close();
//fin.close();
    return 0;
}
