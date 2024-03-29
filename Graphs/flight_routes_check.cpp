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
vl vis;
vl ivis;

 vvl G;
vvl iG;

stack <ll> order;
vector <ll> stronk;
void dfs(int n){
    vis[n] = 1;
    // DEBUG(n);
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
        // DEBUG(child);
        if(!ivis[child]){
            idfs(child);
        }
    }
    stronk.pb(n);
    ivis[n] = 2;
}

void solve(){
    ll n , m;
    cin >> n >> m;

   
    vis.resize(n+1);
    ivis.resize(n+1);
    G.resize(n+1);
    iG.resize(n+1);

    REP(i,m){
        ll a , b;
        cin >> a >> b;
        G[a].pb(b);
        iG[b].pb(a);
    }

  
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }


    ll num_comp = 0;
    while(!order.empty()){
        ll z = order.top();
        order.pop();

        if(!ivis[z]&&!num_comp){
            idfs(z);
            num_comp++;
        }

        else if(!ivis[z] && num_comp){
            unordered_map <ll,ll> hashh;
            for(auto child : G[z]){
                hashh[child] = 1;
            }

            for(auto k : stronk){
                if(!hashh[k]){
                    cout << "NO\n";
                    cout << z << " " << k << "\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";


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