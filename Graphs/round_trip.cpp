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

void dfs(int node, int parent, vvi &G, vi &parents, int &foundloop,int &lastnode, int &lastparent  ){
    if(foundloop){
        return;
    }
  //  DEBUG(node);
    parents[node] = parent;
  //  DEBUG(parents[node]);
    for(auto child : G[node]){
        if(child!=parent && parents[child] == -1 && !foundloop){
            dfs(child,node,G,parents,foundloop,lastnode,lastparent);
        }

        else if(child!=parent && parents[child]!=-1 && !foundloop){
            foundloop = 1;
            lastparent = child;
            lastnode = node;
            return;
        }
    }
}

void solve(){
    int n , m;
    cin >> n >> m;

    vvi G(n+1);

    for(int i = 0 ; i<m;i++){
        int a , b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    vi parent(n+1,-1);
    stack <int> S;
    int lastnode = -1;
    int foundloop = 0;
    int lastparent = -1;

    for(int i = 1;i<n && !foundloop;i++){
        if(parent[i] == -1 ){
            parent[i] = i;
            dfs(i,parent[i],G,parent,foundloop,lastnode,lastparent);
            if(foundloop){
                int start = lastnode;
                vi allans;
               while(start != lastparent){
                   allans.pb(start);

                   start = parent[start];
               }
        //     DEBUG(lastparent);
            cout << allans.size() + 2 << endl;

            cout << lastparent << " ";
            for(auto path: allans){
                cout << path << " ";
            }

            cout << lastparent << " ";
            }
        }

       // cerr <<"\n*******************\n";
    }

    if(!foundloop){
        cout << "IMPOSSIBLE\n";
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