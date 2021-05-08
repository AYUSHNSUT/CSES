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

ll globalLim;
void solve(){

    ll n,q;
    cin >> n >> q;
    vvl G(n+1);

    vl parent(n+1);
    globalLim = 20;
    vvl dp(n+1, vl(globalLim));
    REP(i , n-1){
        ll x;
        cin >> x;

        G[i+2].pb(x);
        parent[x] = i+2;
        dp[i+2][0] = x;
    }
  

    for(int i = 1;i < globalLim;i++){
        for(int z = 1;z<=n;z++){
            dp[z][i] = dp[dp[z][i-1]][i-1];
            // if(i > 3){
            //     continue;
            // }
            // DEBUG(z);
            // DEBUG(i-1);
            // DEBUG(dp[z][i-1]);
        }
    }

    for(int i = 0;i<q;i++){
        ll x , k;
        cin >> x>>k;

        ll curr = x;
        // DEBUG(x);
        // DEBUG(k);
        while(k){
            ll check = log2(k);
            // DEBUG(check);
            ll uncheck = pow(2, check);
            curr = dp[curr][check];
            // DEBUG(curr);
            k-=uncheck;
            // DEBUG(k);

        }
        if(curr == 0) curr = -1;
        cout << curr  << endl;
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
  // cin >> t; 
   while(t--){
       solve();
   }
}