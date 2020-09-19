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
  string s;
  cin >> s;

  vl a(26);

  for(auto c: s)
  {
  //  DEBUG(c-'A');
    a[c-'A']++;
  }
  bool flag = true;
  ll count = 0;
  ll oddind = -1;
  REP(i,26)
  {
    if(a[i]%2)
      {
        count++;
        oddind = i;
        if(count>1)
        {
      //    cout << char('A' + i) << endl;
          flag = false;
          break;
        }

      }
  }
  string s1, s2;
//  DEBUG(flag);
  if(flag)
  {
    REP(i,26)
    {
      if(a[i]%2== 0)
      {
        string temp (a[i]/2, 'A' + i);
        s1 = s1 + temp;
        temp = temp + s2;
        s2 = temp;
      }
    }

    if(oddind != -1)
    {
      string tmp(a[oddind], 'A'+oddind);
      s1 = s1 + tmp;
    }

    cout << s1 << s2 << endl;
  }

  else
    cout << "NO SOLUTION\n";
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
