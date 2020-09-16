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
inline float roundN(float var,int n)
{
    float value = (int)(var * pow(10,n) + .5);
    return (float)value / pow(10,n);
}
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
int main()
{
    //ofstream fout;
    // ifstream fin;
//	fout.open("OUTPUT.txt",ios::out);
//	fin.open("INPUT.txt",ios::in);
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
 
    vi a(n);
 
    REP(i,n)
    {
      cin >> a[i];
    }
    ll sum = 0;
 
    FOR(i,1,n-1)
    {
      if(a[i]<a[i-1])
      {
        sum+= a[i-1] - a[i];
        a[i] = a[i-1];
      }
 
 
    }
 
    cout << sum << endl;
 
//fout.close();
//fin.close();
    return 0;
}