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
 
ll n , q;
vl next_node;
vector <set <ll>> parent_node;
vl visited;
vl lastLooper;
vvl cycles;
vl pos;
vl cid;
vl current_cycle;
vl intimes;
vl outtimes;
 
ll inf = 1e17;
ll startOfloop = -1;
ll cycle_id = 0;
ll pos_in_cycle = 0;
ll time_c = 0;
 
ll up[200005][31];
 
void dfs(ll n){
    visited[n] = 1;
 
 
    ll child = next_node[n];
 
    if(visited[child] == 1){
        // DEBUG(n);
        // DEBUG(child);
        startOfloop = child;
        lastLooper.pb(n);
        parent_node[child].erase(n);
        // for(auto p : parent_node[child]){
        //     DEBUG(p);
        // }
    }
    if(!visited[child]) dfs(child);
 
    if(startOfloop != -1){
        current_cycle.pb(n);
        cid[n] = cycle_id;
        pos[n] = pos_in_cycle++;
 
        if(n == startOfloop){
            startOfloop = -1;
            cycles.pb(current_cycle);
            current_cycle.clear();
            pos_in_cycle = 0;
            cycle_id++;
        }
    }
 
    visited[n] = 2;
}
 
void generate_depth_and_LCA(ll n , ll p){
    intimes[n] = time_c++;
 
    up[n][0] = p;
 
    for(ll i = 1;i<=30;i++){
        if(up[n][i-1]!=-1)
        up[n][i] = up[up[n][i-1]][i-1];
    }
 
    for(auto child : parent_node[n]) generate_depth_and_LCA(child , n);
 
    outtimes[n] = time_c++;
}
 
ll checkancestor(ll a , ll b){
    return intimes[a] <= intimes[b] && outtimes[a] >= outtimes[b];
}
void solve(){
    cin >> n >> q;
 
    next_node.resize(n+1);
    parent_node.resize(n+1);
    pos.resize(n+1,-1);
    cid.resize(n+1,-1);
    intimes.resize(n+1);
    outtimes.resize(n+1);
    visited.resize(n+1);
 
    memset(up , -1, sizeof(up));
 
    for(ll i = 1 ;i<=n;i++){
        ll x; cin >> x;
        // DEBUG(x);
        next_node[i] = x;
        parent_node[x].insert(i);
    }
  
   
    for(ll i = 1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
 
 
    for(auto lastnodes : lastLooper){
        generate_depth_and_LCA(lastnodes,-1);
    }
 
    REP(i,q){
        ll a , b;
        cin >> a >> b;
 
        // DEBUG(a)
        // DEBUG(b);
        // DEBUG(cid[a]);
        // DEBUG(cid[b]);
        // DEBUG(intimes[a]);
        // DEBUG(outtimes[a]);
        // DEBUG(intimes[b]);
        // DEBUG(outtimes[b]);
        if(a == b){
            cout << "0\n";
        }
 
        else if(cid[a]!= -1){
            if(cid[a] == cid[b]){
                ll startpos = pos[a];
                ll endpos = pos[b];
                ll cycsize = cycles[cid[a]].size();
                cout << (startpos - endpos + cycsize)%cycsize << endl;
            }
            else{
                cout << -1 << "\n";
            }
        }
 
        else if(checkancestor(b, a)){
            ll hops = 0;
            for(ll i = 30;i>=0;i--){
                if(up[a][i]!= -1 && !checkancestor(up[a][i], b)){
                    a =  up[a][i];
                    hops += 1<< i;
                }
 
               
            }
             cout << hops + 1 << "\n";
        }
 
        else{
            // cerr << "YE wala\n";
            ll hops = 0;
            for(ll i = 30;i>=0;i--){
                if(up[a][i]!= -1){
                    a =  up[a][i];
                    hops += 1<< i;
                }
 
               
            }
 
            if(cid[a] == cid[b]){
                ll startpos = pos[a];
                ll endpos = pos[b];
                if(cid[a] == -1){
                    cout << -1 << endl;
                    continue;
                }
                ll cycsize = cycles[cid[a]].size();
 
                cout << (startpos - endpos + cycsize)%cycsize + hops << endl; 
                }
            
            else{
                cout << -1 << "\n";
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
  // cin >> t; 
   while(t--){
       solve();
   }
}