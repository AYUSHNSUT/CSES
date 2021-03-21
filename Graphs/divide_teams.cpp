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


void dfs(int node , int color , vvi &G,vi &c, int &err){
    //DEBUG(node);
    if(err){
        return;
    }

    c[node] = color;


    for(auto child : G[node]){
        if(c[child] != -1 && c[child]!= color^1){
            err = 1;
            return;
        }
        if(c[child] == -1)
        dfs(child,color^1,G,c,err);;
    }
}

void solve(){

    int n , m;
    cin >> n >> m;

    vvi G(n+1);
    vector <pii> edgeList;
    REP(i,m){
        int a,b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);

        edgeList.pb({a,b});
    }


    vector <int> colours(n+1,-1);
    int err = 0;
    for(int i = 1;i<=n;i++){
        if(colours[i] == -1){
            dfs(i,0,G,colours,err);
        }
    }

    if(err){
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(int i = 1;i<=n;i++){
        cout << colours[i] + 1 <<  " ";
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