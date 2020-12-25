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
  ll n,x;
  cin >> n >> x;

  vector < pair <ll,ll> > a(n);

  REP(i,n)
  {
    cin >> a[i].first;
    a[i].second = i+1;
  }

  sort(all(a));

  for(int i = 0;i<n;i++)
  {
    ll t1 = a[i].first;

    if(t1 > x){
      break;
    }
    for(int j = i+1;j<n;j++){
      ll t2 = a[j].first;

      if(t1 + t2 > x){
        break;
      }

      for(int k = j+1, l = n-1;k<l;k++){

        while(k < l && t1 + t2 + a[k].first + a[l].first > x){
          l--;
        }

        if(k < l &&  t1 + t2 + a[k].first + a[l].first == x){
          cout << a[i].second << " " << a[j].second << " " << a[k].second << " " << a[l].second << "\n";
          return;
        }
      }
    }
  }

  cout << "IMPOSSIBLE\n";
  return;
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
