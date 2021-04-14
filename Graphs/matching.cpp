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
ll n;
ll get_flow_by_bfs(vvl &G, vvl &adj, vl&parent){
    fill(parent.begin(), parent.end(),-1);
    queue <pll> q;
    q.push({0,M});
    parent[0] = 0;

    while(!q.empty()){
        pll currp = q.front();
        q.pop();
        ll curr = currp.first;
        ll c_flow = currp.second;
        // DEBUG(curr);

        for(auto child : adj[curr]){
            if(parent[child]== -1 && G[curr][child]){
                parent[child] = curr;
                ll this_flow = G[curr][child];
                this_flow = min(this_flow , c_flow);
                if(child == n-1){
                    return this_flow;
                }
                q.push({child , this_flow});
            }
        }
    }

    return 0;
}
void solve(){
    ll boys,girls,m;
    cin >> boys >> girls >> m;
    n = boys+girls+2;
    vvl G(n);
    vvl cap(n, vl(n));

    REP(i,m){
        ll a ,b;
        cin >> a >> b;
        if(cap[a][boys+b]) continue;
        G[a].pb(boys + b);
        G[boys+b].pb(a);
        cap[a][boys+b] = 1;
    }

    for(int i = 1;i<=boys;i++){
        G[0].pb(i);
        cap[0][i] = 1;
    }
     for(int i = boys+1;i<=boys+girls;i++){
        G[i].pb(n-1);
        cap[i][n-1] = 1;
    }

    ll new_flow;
    ll tot_flow = 0;
    vl parent(n);
    while(new_flow = get_flow_by_bfs(cap,G,parent)){
        tot_flow += new_flow;
        // DEBUG(new_flow);
        ll b = n-1;
        ll a = parent[n-1];

        while(true){
            // DEBUG(a);
            // DEBUG(b);
            cap[a][b] -= new_flow;
            cap[b][a] += new_flow;
            if(a==0) break;
            b = a;
            a = parent[a];
        }
    }

    cout << tot_flow << endl;

    for(int i = 1;i<=boys;i++){
        for(auto girl : G[i]){
            if(cap[i][girl] == 0){
                cout << i << " "<< girl - boys << "\n";
            }
        }
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