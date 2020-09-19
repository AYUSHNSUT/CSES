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
string pattern;
int c = 0;

int a[7][7];

bool bounded(int x, int y)
{
  return x>= 0 && x<=6 && y>=0 && y <= 6;
}

bool valid(int a[7][7], int r, int c)
{
  return bounded(r,c) && a[r][c] !=1 ;
}

void backtrack(int a[7][7], int i, int ro,  int co) {
    if (ro == 6 && co == 0) {
    //  DEBUG(i);
        if (i == 48 ) ++c;
        return;
    }

    if ((pattern[i] == '?' || pattern[i] == 'U') &&
        valid(a, ro - 1, co)) {
        bool locked = !valid(a, ro - 2, co) &&
                      valid(a, ro - 1, co - 1) &&
                      valid(a, ro - 1, co + 1);

        if (!locked) {
            a[ro - 1][co] = 1;
            backtrack(a,i + 1, ro - 1, co);
            a[ro - 1][co] = 0;
        }
    }

    if ((pattern[i] == '?' || pattern[i] == 'D') &&
        valid(a, ro + 1, co)) {
        bool locked = !valid(a, ro + 2, co) &&
                      valid(a, ro + 1, co - 1) &&
                      valid(a, ro + 1, co + 1);

        if (!locked) {
            a[ro + 1][co] = 1;
            backtrack( a, i + 1, ro + 1, co);
            a[ro + 1][co] = 0;
        }
    }

    if ((pattern[i] == '?' || pattern[i] == 'L') &&
        valid(a, ro, co - 1)) {
        bool locked = !valid(a, ro, co - 2) &&
                      valid(a, ro - 1, co - 1) &&
                      valid(a, ro + 1, co - 1);

        if (!locked) {
            a[ro][co - 1] = true;
            backtrack( a, i + 1, ro, co - 1);
            a[ro][co - 1] = false;
        }
    }

    if ((pattern[i] == '?' || pattern[i] == 'R') &&
        valid(a, ro, co + 1)) { // R
        bool locked = !valid(a, ro, co + 2) &&
                      valid(a, ro - 1, co + 1) &&
                      valid(a, ro + 1, co + 1);

        if (!locked) {
            a[ro][co + 1] = true;
            backtrack(a, i + 1, ro, co + 1);
            a[ro][co + 1] = false;
        }
    }
}



void solve()
{
  cin >> pattern;
  a[0][0] = 1;
  backtrack(a,0,0,0);
  cout << c << endl;

  // REP(i,7)
  // {
  //   REP(j,7)
  //   {
  //     cout << a[i][j] << " ";
  //   }
  //   cout << endl;
  // }
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
