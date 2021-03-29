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

void dfs(int source,int pr,vvl &G,vl &visited, unordered_map<ll,ll> &parent, int &foundloop,int &lastnode,int &lastnodeparent){
  
    if(foundloop){
        return;
    }
    visited[source] = 1;
    parent[source] = pr;
    
 

    for(auto cc: G[source]){

        if(!visited[cc] && !foundloop){
     
            parent[cc] = source;
            dfs(cc,source,G,visited,parent,foundloop,lastnode,lastnodeparent);
        }

        else if(visited[cc] && parent[cc] && !foundloop){

            foundloop = 1;
            lastnode = cc ;
            lastnodeparent = source;
            return;
        }
    
    }

    if(!foundloop){
        parent[source] = 0; 
    }

}
void solve(){

    ll n,m;
    cin >> n >> m;

    vvl G(n+1);
    REP(i,m){
        ll a  , b;
        cin >> a >> b;

        G[a].pb(b);
    }

    int foundloop = 0;
    int lastnode = 1;
    int lastnodeparent = -1;
    vl visited(n+1);
    for(int i = 1;i<=n;i++){
        if(!visited[i] && !G[i].empty()){
       
            unordered_map <ll,ll> parent;
            parent[i] = i;
            dfs(i,i,G,visited,parent,foundloop,lastnode,lastnodeparent);
           
            if(foundloop){
                int start = lastnodeparent;
                vi ans;
                ans.pb(lastnode);
                while(start!=lastnode){
                    ans.pb(start);
                    start = parent[start];
                }
                ans.pb(lastnode);

                reverse(all(ans));

                cout << ans.size() << "\n";

                for(auto it : ans){
                    cout << it << " ";
                }
                return;
            }
            
        }
    }
    

    cout << "IMPOSSIBLE\n";
    return;

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