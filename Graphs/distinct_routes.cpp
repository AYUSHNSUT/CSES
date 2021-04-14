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
vl currpath;
vvl fullpaths;
void dfs(ll source,vvl&G, vvl&flowgraph, vl & currpath, bool &found,vvl &edgedone){
    currpath.pb(source);
    // DEBUG(source);
    if(source == n){
        fullpaths.pb(currpath);
        found = true;
        return;
    }
    if(found){
        return;
    }
    for(auto child: G[source]){
        if(found) return;
        if(flowgraph[source][child] < 0 && !found && !edgedone[source][child]){
            dfs(child,G,flowgraph,currpath,found,edgedone);
        }
    }
}
void dfs_help(vvl&G, vvl&cap, vvl &flowgraph){
    vvl edgedone(n+1 , vl(n+1));
    for(auto child: G[1]){
        // cerr << "\n********\n";
        //  DEBUG(child);
        //  DEBUG(flowgraph[1][child]);
        if(flowgraph[1][child] < 0){
            bool found = 0;
            currpath.clear();
            currpath.pb(1);
            edgedone[1][child] = 1;
            dfs(child,G,flowgraph,currpath,found,edgedone);

            for(int i = 0;i<currpath.size() -1 ;i++){
                edgedone[currpath[i]][currpath[i+1]] = 1;
            }
        }
    }
}

ll get_flow_by_bfs(vvl &G, vvl &adj, vl&parent, vvl &flowgraph){
    //  cerr << "\n*************\n";
    fill(parent.begin(), parent.end(),-1);
    queue <pll> q;
    vl visited(n+1);
    q.push({1,M});
    parent[1] = 1;
 
    while(!q.empty()){
        pll currp = q.front();
        q.pop();
        ll curr = currp.first;
        ll c_flow = currp.second;
        // DEBUG(curr);
        for(auto child : adj[curr]){
            // DEBUG(child);
            // DEBUG(G[curr][child]);
            // DEBUG(flowgraph[curr][child]);
            // DEBUG(parent[child]);
            if(parent[child]== -1 && (G[curr][child] + flowgraph[curr][child])){
                // cerr << "Andar\n";
                parent[child] = curr;
                ll this_flow = G[curr][child]+flowgraph[curr][child];
                this_flow = min(this_flow , c_flow);
                if(child == n){
                    return this_flow;
                }
                q.push({child , this_flow});
            }
        }
    }
 
    return 0;
}
void solve(){
    cin >> n >> m;
 
    vvl G(n+1, vl(n+1));
    vvl adjList(n+1);
    vvl flowgraph(n+1, vl(n+1));
    REP(i,m){
        ll a , b;
        cin >> a >> b;
        ll c = 1;
        G[a][b]+= c;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    ll new_flow;
    ll tot_flow = 0;
    vl parent(n+1);
    while(new_flow = get_flow_by_bfs(G,adjList,parent,flowgraph)){
        // cerr << "\n*************\n";
        tot_flow += new_flow;
        // DEBUG(new_flow);
        ll b = n;
        ll a = parent[n];
  
        while(true){
            // DEBUG(a);
            // DEBUG(b);
            flowgraph[a][b] -= new_flow;
            flowgraph[b][a] += new_flow;
            // DEBUG(flowgraph[a][b]);
            // DEBUG(flowgraph[b][a]);
            if(a==1) break;
            b = a;
            a = parent[a];
        }
      
    }

    dfs_help(adjList,G,flowgraph);
 
    cout << fullpaths.size() << "\n";
 
    for(auto p : fullpaths){
        cout << p.size() << endl;
        for(auto node : p){
            cout << node << " ";
        }
        cout << "\n";
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