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

const ll inf = 1e18;
class Edge{
    public:
    ll from;
    ll to;
    ll weight;

    Edge() : from(0), to(0), weight(0){}
    Edge(const ll a,const ll b,const ll c) : from(a), to(b), weight(c) {

    }
};

void find_next(int &x,vi &visited){
    for(int r = x+1;r<visited.size();r++){
        if(!visited[r]){
            x = r;
            return;
        }
    }
    x=visited.size();
}

void dfs(int source,vi&avail, vi&visited,vvl &G){
    visited[source] = 1;
    avail.pb(source);

    for(auto node : G[source]){
        if(!visited[node]){
            dfs(node,avail,visited,G);
        }
    }
}

void solve(){
    ll n , m;
    cin >> n >> m;
    vector<Edge>G;
    vvl Gr(n+1);
    REP(i,m){
        ll a , b, c;
        cin >> a >> b >> c;
        Edge e = Edge(a,b,c);
        Gr[a].pb(b);
        // DEBUG(e.from);
        // DEBUG(e.to);
        // DEBUG(e.weight);
        G.pb(e);
    }

    vector <int> hashmap(m);


    vl parent(n+1, -1);
    vl distance(n+1, inf);
    distance[1] = 0;
    vi visited(n+1);
    
    ll x = -1;
    int k = 1;

    while(k<=n){
        // DEBUG(k);
        // cerr << visited[k];
        if(!visited[k])
        {
            vector <int> availiblenodeList;
            vector<int> curriter(n+1);
            dfs(k,availiblenodeList,curriter,Gr);
            int V = availiblenodeList.size();
            vector<Edge> newG;
            for(auto e: G){
                if(curriter[e.from] || curriter[e.to]){
                    newG.pb(e);
                }
            }
            visited[k] = 1;
            distance[k] = 0;
            for(int i = 1;i<=V;i++){
            x = -1; 

            for(auto e:newG){
                ll u = e.from;
                ll v= e.to;
                ll wt = e.weight;
            // DEBUG(u);
            // DEBUG(distance[u]);
            //   DEBUG(v);
            // DEBUG(distance[v]);
            // DEBUG(wt);

                if(distance[u]!=inf && distance[u] + wt < distance[v]){
                    visited[v] = 1;
                    distance[v] = distance[u] + wt;
                    x = v;
                    parent[v] = u;
                }
            }
         }

        }

        find_next(k,visited);

        if(x!=-1){
            break;
        }
    

    }
    


    if(x==-1){
        cout << "NO\n";
        return;
    }

    else{

        for(int i = 1;i<=n;i++){
            x = parent[x];
        }

        vl ans;

        for(int v = x;;v = parent[v]){
            ans.pb(v);

            if(v==x && ans.size()>1){
                break;
            }
        }

        reverse(all(ans));
        cout << "YES\n";
        for(auto z : ans){
            cout << z << " ";
        }
        return;
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