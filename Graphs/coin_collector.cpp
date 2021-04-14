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
stack<ll>order;
vvl G, iG;
vl vis , ivis;
vl costnodes;
vvl SCC;
vl  currSCC;
vl scc_num;
ll cost=0;
ll scc_count = 0;
vl costs;
unordered_map<ll,ll> part_of_some_scc;
void dfs(int n){
    vis[n] = 1;

    for(auto child : G[n]){
        if(!vis[child]){
            dfs(child);
        }
    }

    order.push(n);
    vis[n] = 2;
}

void idfs(int n){
    ivis[n] = 1;
    // DEBUG(n);
    for(auto child : iG[n]){
        if(!ivis[child]) idfs(child);
    }

   
    currSCC.pb(n);
    ivis[n] = 2;
}
void solve(){
    cin >> n >> m;

    G.resize(n+1);
    iG.resize(n+1);
    costnodes.resize(n+1);
    vis.resize(n+1);
    ivis.resize(n+1);
    scc_num.resize(n+1);

    for(int i = 1;i<=n;i++){
        cin >> costnodes[i];
    }
    REP(i,m){
        ll a,b;
        cin >> a >> b ;
        G[a].pb(b);
        iG[b].pb(a);
    }

    for(int i = 1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }

    while(!order.empty()){
        ll z = order.top();
        order.pop();
        // DEBUG(z);
        // DEBUG(ivis[z]);

        if(!ivis[z]){
            idfs(z);
            SCC.pb(currSCC);
            costs.pb(0);
            for(auto elem : currSCC){
                scc_num[elem] = scc_count;
                part_of_some_scc[elem] = 1;
                costs[scc_count]+=costnodes[elem];
            }

            currSCC.clear();
            scc_count++;
        }
    }

    // for(auto scc : SCC){
    //     for(auto nodes : scc){
    //         DEBUG(nodes);
    //     }
    //     cerr << "\n********\n";
    // }

    ll N = SCC.size();
    vl indegree(N);
    vl outdegree(N);
    vvl GS(N);
    vvl iGS(N);

    for(auto scc : SCC){
        for(auto nodes:scc){
            // DEBUG(nodes);
            for(auto child: G[nodes]){
                // DEBUG(child);
                // DEBUG(scc_num[child]);
                if(scc_num[child]!=scc_num[nodes]){
                    GS[scc_num[nodes]].push_back(scc_num[child]);
                    indegree[scc_num[child]]++;
                    outdegree[scc_num[nodes]]++;
                    iGS[scc_num[child]].pb(scc_num[nodes]);
                }
            }
        }
    }

    queue<int> q;
    for(int i = 0;i<N;i++){
        if(outdegree[i] == 0){
            q.push(i);
        }
    }

    vl dp(N);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto child : iGS[curr]){
            if(!dp[child]){
                dp[child] = costs[curr] + dp[curr];
            }
            else{
                dp[child] = max(dp[child], costs[curr] + dp[curr]);
            }
            outdegree[child]--;
            if(!outdegree[child]){
                q.push(child);
            }
        }
    }

    ll maxx = -1;

    for(int i  = 0;i<N;i++){
        maxx = max(maxx, dp[i]+costs[i]);
    }

    cout << maxx << endl;




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
 //  cin >> t; 
   while(t--){
       solve();
   }
}