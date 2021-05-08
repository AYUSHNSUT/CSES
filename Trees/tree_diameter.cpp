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
vl maxHeight;
vl maxAns;
unordered_map<ll,ll> vis;
ll dfs(ll source, ll parent, vvl &G){

    vis[source] =1;

    if(maxHeight[source]!= -1){
        return maxHeight[source];
    }

    vector <ll> childHeights;

    for(auto child : G[source]){
        // DEBUG(child);
        if(!vis[child] && child != parent)
        childHeights.pb(1 + dfs(child,source,G));
    }

    if(childHeights.size() == 0){
        maxHeight[source] = 0;
        maxAns[source] = 0;
        return 0;
    }
    // DEBUG(source);
    // DEBUG(G[source].size());

    sort(all(childHeights));
    reverse(all(childHeights));

    // for(auto chiildh : childHeights){
    //     DEBUG(chiildh);
    // }
    if(childHeights.size() == 1){
        maxHeight[source] = childHeights[0];
        maxAns[source] = childHeights[0];
        return childHeights[0];
    }

    maxHeight[source] = childHeights[0];
    maxAns[source] = childHeights[0] + childHeights[1];

    // cerr << "Ye return ho rha " << source  << "\n";
    return maxHeight[source];
    
}

void solve(){

    ll n;
    cin >> n;

    vvl G(n+1);
    maxHeight.resize(n+1,-1);
    maxAns.resize(n+1,-1);

    REP(i,n-1){
        ll a , b;
        cin >> a >> b;
        // DEBUG(a);
        // DEBUG(b);
        G[a].pb(b);
        G[b].pb(a);
    }

    // REP(i,n){
    //     DEBUG(i+1);
    //     for(auto k : G[i+1]){
    //         DEBUG(k);
    //     }
    // }

    dfs(1,1,G);
    ll ans = -1;

    for(int i = 1;i<=n;i++){
        ans = max(ans, maxAns[i]); 
    }

    cout << ans << endl;

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