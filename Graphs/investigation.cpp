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

const ll inf = 1e17;

class possibilty{
    public:
    ll costsofar;
    ll vertex;

    possibilty() : costsofar(0) , vertex(0){}
    possibilty(ll a, ll b) : costsofar(a) , vertex(b){}
     
};

bool operator < (const possibilty p1, const possibilty p2){
    return p1.costsofar > p2.costsofar;
}
void bfs(int source, vector <vector<pll>> &G,vl &vis){

    queue<ll> q;
    q.push(source);
    vis[source] = 1;
    while(!q.empty()){
        ll curr = q.front();
        DEBUG(curr);
        q.pop();

        for(auto chil : G[curr]){
            if(!vis[chil.first]){
                vis[chil.first] = 1;
                q.push(chil.first);
            }
        }
    }
   
}

void solve(){
    ll n , m;
    cin >> n >> m;

    vector <vector <pll>> G(n+1);
    vector <vector <pll>> iG(n+1);

    REP(i,m){
        ll a , b ,c;
        cin >> a >> b >> c;
        G[a].pb({b,c});
        iG[b].pb({a,c});
 
    }


    // unordered_map <ll,ll> otw;
    // vl vis(n+1);
    // bfs(n,iG,vis);

    priority_queue <possibilty> pq;
    possibilty ptemp(0,1);
    pq.push(ptemp);



    vl distance(n+1, inf);
    ll count = 0;
    distance[1] = 0;


    vl maxvertex(n+1, -inf);
    vl minvertex(n+1, inf);

    minvertex[1] = 0;
    maxvertex[1] = 0;

    vl vis(n+1);
    vl dp(n+1);
    dp[1] = 1;

    while(!pq.empty()){
        possibilty curr = pq.top();
        ll wt = curr.costsofar;
        ll v = curr.vertex;
        pq.pop();
        if(vis[v]) continue;

        vis[v] = 1;
        // DEBUG(v);
        // if(!vis[v]) continue;

        for(auto chil : G[v]){
            ll child = chil.first;
            ll edgewt = chil.second;
            if(vis[child]) continue;
            if(distance[child] == inf || distance[child] > edgewt + wt){
                distance[child] = edgewt + wt;
                dp[child] = dp[v];
                 dp[child]%=M;
                maxvertex[child] = maxvertex[v] + 1;
                 minvertex[child] =minvertex[v] + 1;
                if(child == n) continue;
                possibilty newp(distance[child], child);
                pq.push(newp);
            }
            else if(distance[child] == edgewt + wt){
                dp[child] += dp[v];
                dp[child]%=M;
                maxvertex[child] = max(maxvertex[child],maxvertex[v] + 1);
                minvertex[child] = min(minvertex[child],minvertex[v] + 1);
                if(child == n) continue;
                possibilty newp(chil.second + wt , chil.first );
                pq.push(newp);
            }
            
        }
    }

    cout << distance[n] << " " << dp[n] << " " << minvertex[n] << " " << maxvertex[n] << endl;

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