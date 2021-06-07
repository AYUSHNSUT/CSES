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
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
#define fast_cin() std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////


void solve(){
    ll n , m;
    cin >> n >> m;
    vvl a(n+1, vl(n+1));
    REP(i,n){
        REP(j,n){
            char c;
            cin >> c;

            if(c == '.'){
                continue;
            }
            a[i+1][j+1] = 1;
        }
    }

    // REP(i,n){
    //     REP(j,n){
    //         cerr << a[i+1][j+1] << " ";
    //     }
    //     cerr << endl;
    // }

    vvl pre(n+1, vl(n+1));

    vvl up(n+1,vl(n+1));
    vvl left(n+1,vl(n+1));

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            // DEBUG(i);
            // DEBUG(j);

            up[i][j]+=up[i-1][j] + a[i-1][j];
            left[i][j] += left[i][j-1] + a[i][j-1] ;
            pre[i][j] += pre[i-1][j-1] + up[i][j] + left[i][j] + a[i][j] ;
            // DEBUG(up[i][j]);
            //  DEBUG(left[i][j]);
            //   DEBUG(pre[i][j]);
        }
    }

    REP(i,m){
        ll y1,x1,y2,x2;
        cin >> x1 >> y1 >> x2 >> y2;
        // DEBUG(x2);
        // DEBUG(y2);
        // DEBUG(x1);
        // DEBUG(y1);
        // DEBUG(pre[x2][y2]);
        // DEBUG(pre[x2-1][y1-1]);

        // DEBUG(pre[x1-1][y2-1]);
        // DEBUG(pre[x1-1][y1-1]);
        cout << pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1] << endl;
    }
}



int main(){



    #ifdef mishrable
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif



   fast_cin();
   int t =1;
   //cin >> t; 
   while(t--){
       solve();
   }
}