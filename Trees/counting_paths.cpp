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

vvl G;
vl c;
vl levels;
vvl dp;
unordered_map<ll,ll> cache;


const ll zz = 300000;

ll chec(ll a, ll b){
    return a*zz + b;
}
void bfs(ll source, ll parent){
    
    queue<ll> Q;

    Q.push(source);
    dp[source][0] = parent;
    levels[source] = 0;

    while(!Q.empty()){
        ll curr = Q.front();
        Q.pop();

        for(auto k : G[curr]){
            if(k^dp[curr][0]){
                levels[k] = levels[curr]+1;
                dp[k][0] = curr;
                Q.push(k);
            }
        }
    }
}

ll LCA(ll a , ll b){

    if(levels[a] < levels[b]){
        swap(a,b);
    }

    ll d  = levels[a] - levels[b];

    while(d){
        ll p = log2(d);
        a = dp[a][p];
        d -= (1 << p);
    }

    if(a == b){
        return a;
    }

     for(int i = 19;i>=0;i--){

         if(dp[a][i]!=dp[b][i]){
             a=dp[a][i];
             b = dp[b][i];
         }
             
     }
    return dp[a][0];
}

void dfs2(ll source, ll parent){
    ll x = c[source];

    for(auto child : G[source]){
        if(child^parent){
            dfs2(child,source);
            x+=c[child];
        }
    }

    c[source] = x;
}

void solve(){

    ll n,q;
    cin >> n>>q;
    G.resize(n+1);
    c.resize(n+1);
    levels.resize(n+1);
    dp.resize(n+1, vl(20));

    REP(i,n-1){
        ll a , b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    levels[0] = -1;

    bfs(1,0);

    for(int i = 1;i<20;i++){
        for(int j = 1;j<=n;j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    // cerr << "Here\n";

    for(int i = 0;i<q;i++){

        // if(i%10000 == 0){
        //     DEBUG(i);
        // }
        ll a , b;
        cin >> a >> b;
        c[a]++;
        c[b]++;

        ll d = LCA(a,b);

        c[d]--;

        if(d!=0)
            c[dp[d][0]]--;
    }

    dfs2(1,0);

    for(int i = 1;i<=n;i++){
        cout << c[i] << " ";
    }
    cout << "\n";
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