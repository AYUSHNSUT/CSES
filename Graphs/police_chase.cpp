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

ll n,m;

ll bfs(vvl &G, vvl &cap, vl&parent){
    fill(all(parent), -1);
    queue <pll> q;
    q.push({1,M});
    parent[1] = 1;
    while(!q.empty()){
        ll curr = q.front().first;
        ll cap_so_far = q.front().first;
        q.pop();

        for(auto child : G[curr]){
            if(parent[child] == -1 && cap[curr][child]){
                parent[child] = curr;
                ll this_cap = cap[curr][child];
                cap_so_far = min(cap_so_far,this_cap);
                if(child == n){
                    return cap_so_far;
                }

                q.push({child,cap_so_far});
            }
        }
    }
    return 0;
}

void dfs(ll source, vvl &G, vector <pll> &edgeList, vl&visited,vvl &cap){
    visited[source] = 1;
    // DEBUG(source);

    for(auto child : G[source]){
        // DEBUG(child);
        // DEBUG(visited[child]);
        // DEBUG(cap[source][child]);
        if(!visited[child]){
            if(cap[source][child] == 0){
                edgeList.pb({source, child});
            }
            else{
                dfs(child,G,edgeList,visited,cap);
            }
        }
    }

}
void solve(){
    cin >> n >> m;
    vvl cap(n+1,vl(n+1));
    vvl G(n+1);
    REP(i,m){
        ll a , b ;
        cin >> a >> b;
        ll c= 1;
        cap[a][b] += c;
        cap[b][a] += c;
        G[a].pb(b);
        G[b].pb(a);
    }

    ll tot_flow = 0, new_flow = 0;
    vl parent(n+1);
    while(new_flow = bfs(G,cap,parent)){
        tot_flow += new_flow;
        ll b = n;
        ll a = parent[n];
        // DEBUG(new_flow);
        while(true){
            cap[a][b]-=new_flow;
            cap[b][a]+=new_flow;
            // DEBUG(a);
            // DEBUG(b);
            if(a == 1) break;
            b = a;
            a = parent[a];
        }
    }
    DEBUG(tot_flow);

    vector <pll> edgeList;
    vector <ll> visited(n+1);

    dfs(1,G,edgeList,visited,cap);
    vector <pll> newList;
    
    for(auto e: edgeList){
        if(visited[e.first] && visited[e.second]){
            continue;
        }
        newList.pb(e);
    }

    cout << newList.size() << "\n";

    for(auto e: newList){
        cout << e.first << " " << e.second << "\n";
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