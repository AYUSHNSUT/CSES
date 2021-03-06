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

bool valid (ll mid , vl &a, ll k)
{
    ll gc = 1;
    ll currSum = 0;
    for(int i = 0;i<a.size();i++){
      if(a[i] > mid){
        DEBUG(a[i]);
        DEBUG(mid);
        return false;
      }
      if(currSum + a[i] > mid)
      {
        gc++;
        currSum = a[i];
      }

      else{
        currSum += a[i];
      }
    }

    DEBUG(gc);
    if(gc <=k)
    {
      return true;
    }
    else return false;
}
void solve()
{
  ll n, k;
  cin >> n >> k;

  vl a(n);
  REP(i,n){
    cin >> a[i];
  }
  ll low = 1, hi = 1e18;

  ll mid; ll ans = 0;
  while(low <= hi){
    mid = (low + hi) /2;
    DEBUG(mid);
    bool pos = valid(mid, a,k);
  //  DEBUG(mid);
    DEBUG(pos);
    if(pos){
      ans = mid;
      hi = mid-1;
    }
    else
    {
      low = mid+1;
    }
  }

  cout << ans << endl;

}

int main()
{

    std::ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;

    while(t--)
      {
        solve();
      }




//fout.close();
//fin.close();
    return 0;
}
