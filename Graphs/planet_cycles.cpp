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
vl G;
vl visited;
vl dp;
vl cycleSize;
vl currloop;

ll startLoop = -1;
void dfs(ll n){
    visited[n] = 1;
    // DEBUG(n);
  

    ll child = G[n];
    //   DEBUG(child);
    //   DEBUG(visited[child]);

    if(visited[child] == 2){
        dp[n] = dp[child] + 1;
        cycleSize[n] = cycleSize[child];
        visited[n] = 2;
        return;
    }

    if(visited[child] == 1){
        startLoop = child;
    }
    if(!visited[child]) dfs(child);

    if(startLoop != -1){
        dp[n] = 0;
        currloop.pb(n);

        if(startLoop == n){
            startLoop = -1;
            for(auto k : currloop){
                cycleSize[k] = currloop.size(); 
            }
            currloop.clear();
        }
    }
    else{
         dp[n] = dp[child] + 1;
        cycleSize[n] = cycleSize[child];
        visited[n] = 2;
        return;
    }

    visited[n] = 2;
}
void solve(){
    cin >> n;

    
    G.resize(n+1);
    visited.resize(n+1);
    dp.resize(n+1);
    cycleSize.resize(n+1);
    REP(i,n){
        cin >> G[i+1];
    }

    for(int i = 1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }


    for(int i = 1;i<=n;i++){
        // DEBUG(i);
        // DEBUG(dp[i]);
        // DEBUG(cycleSize[i]);
        cout << dp[i] + cycleSize[i] << " ";
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