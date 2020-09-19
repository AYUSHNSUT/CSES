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

map <int,int> row, colu, diag1,diag2;
int a[8][8];
int b[8][8];
vector <string> s;
int placed = 0;
int c = 0;
void backtrack(int ro)
{
  if(placed == 8)
    {
      c++;
      // REP(i,8)
      // {
      //   REP(j,8)
      //   {
      //     cout << b[i][j] << " ";
      //   }
      //   cout << endl;
      // }
      // cout << "****************\n";
      return;
    }

  for(int i = 0;i<8;i++)
  {
    if(a[ro][i] == 0)
    {
      if(row[ro] == 0 && colu[i] == 0 && diag1[ro - i] == 0 && diag2[ro + i] == 0)
      {
        row[ro ] = 1;
        colu[i] = 1;
        diag1[ro - i] = 1;
        diag2[ro+i] = 1;
        placed++;
        b[ro][i] = 1;
        backtrack(ro+1);
          b[ro][i] = 0;
        row[ro ] = 0;
        colu[i] = 0;
        diag1[ro - i] = 0;
        diag2[ro+i] = 0;
        placed--;
      }
    }
  }

}

void solve()
{
  vector <string> s;
  REP(j,8)
  {
    string tmp;
    cin >> tmp;
    s.pb(tmp);
    for(int i = 0;i<8;i++)
    {
      if(tmp[i] == '*')
      {
        a[j][i] = 1;
      }
    }
  }

  backtrack(0);
  cout << c << endl;
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
/*
........
........
........
........
........
........
........
........





*/
