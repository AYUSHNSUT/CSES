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
    ll n , m , q;
    cin >> n >> m >> q;
    vector <vector <ll> > a(n , vector <ll>(n,(ll)(1e15 + 1)));

    REP(i,m){
        int x , y;
        cin >> x >> y;
        ll z;
        cin >> z;

        a[x-1][y-1] = min(a[x-1][y-1], z);
        a[y-1][x-1] = a[x-1][y-1];
    }

    for(int node = 0;node<n;node++){
        for(int i = 0;i<n;i++){
            for(int j= 0; j<n;j++){
                if(i==j){
                    a[i][j] = 0;
                    continue;
                }

                if(i == node || j == node){
                    continue;
                }

                if(a[i][j] > a[i][node] + a[node][j]){
                    a[i][j] = a[i][node] + a[node][j];
                }
                
            }
        }
    }


    REP(i,q){
        int x, y;
        cin >> x >> y; 
        ll t = a[x-1][y-1] == (ll)(1e15+1) ? -1 : a[x-1][y-1] ;
        cout << t << "\n";
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
 //  cin >> t; 
   while(t--){
       solve();
   }
}