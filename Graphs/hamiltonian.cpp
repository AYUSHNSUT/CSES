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

ll n , m;
ll transform(ll x, ll y){
    return x*n + y;
}
void solve(){
    cin >> n >> m;

    vvl G(n);
    vvl iG(n);


    REP(i,m){
        ll a , b;
        cin >> a >> b;
        G[a-1].pb(b-1);
        iG[b-1].pb(a-1);
    }

    vvl dp((1<<(n)), vl(n));
    dp[1][0] = 1;
    
    for(int i = 1;i< 1 << (n);i+=2){
        // DEBUG(i);
        if(__builtin_popcount(i) == 1){
            continue;
        }
        if(i & (1 << (n-1)) && __builtin_popcount(i) != n){
            continue;
        }
        // string bini;
        // bini = bitset<20>(i).to_string();
        // DEBUG(bini);
        for(int j = 1;j<n;j++){
            if(j == n-1 && i!= (1<<n)-1){
                continue;
            }
            if(i & 1<<j){
                // DEBUG(j);
                ll previousiter = i^(1<<j);
                // DEBUG(bitset<4>(previousiter).to_string());
                //yaha
                for(auto neighbours : iG[j]){
                    if(neighbours == n-1){
                        continue;
                    }
                    // DEBUG(neighbours);
                    if(i & (1<<neighbours)){
                        dp[i][j] += dp[previousiter][neighbours]%M;
                        dp[i][j]%=M;
                        // DEBUG(dp[i][j]);
                    }
                }
            }
        }
    }
    
    DEBUG((1<<n) - 1);
    DEBUG(n-1);
    cout << dp[(1<<n) - 1][n-1] << endl;

    
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
  // cin >> t; 
   while(t--){
       solve();
   }
}