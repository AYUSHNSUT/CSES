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
  int n ,x;
  cin >> x >> n;

  map <int,int> mapp;
  mapp[x] = 1;
  set <int> S;
  S.insert(0);
  S.insert(x);
  REP(i,n){
    int t;
    cin >> t;
    //DEBUG(t);s
    auto it = S.lower_bound(t);
    // DEBUG(*it);
    int r  = *it;
    it--;
    int l = *it;
    // DEBUG(l);
    // DEBUG(r);
    mapp[r-l]--;

    if(!mapp[r-l]){
      mapp.erase(r-l);
    }
      S.insert(t);

    mapp[r - t]++;
    mapp[t - l]++;

    auto ansfin = mapp.end();
    ansfin--;

    int ans = ansfin->first;

    cout << ans << " ";


  }
  cout << "\n";

  return;
}

int main()
{

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
