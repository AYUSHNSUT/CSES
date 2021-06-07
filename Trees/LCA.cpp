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
    vi levels;
    int lim = 20;

     vvi dp;
     vvi G;

void bfs(int source, int parent, int level){
    levels[source] = level;

    queue<int> Q;

    for(auto child : G[source]){
        Q.push(child);
        dp[child][0] = source;
        levels[child] = levels[source] + 1;
    }

    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();

        for(auto z: G[curr]){
            if(z != dp[curr][0]){
                   Q.push(z);
                   dp[z][0] = curr;
                   levels[z] = levels[curr] + 1;
            }
        }
    }
}
void solve(){

    int n,q;
    cin >> n >> q;

    G.resize(n+1);

    levels.resize(n+1);
    dp.resize(n+1, vi(lim));

    REP(i,n-1){
        int a , b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

     bfs(1,0,0);


     for(int i = 1;i<lim;i++ ){
               for(int j = 1;j<=n;j++){
                 dp[j][i] = dp[dp[j][i-1]][i-1];
         }
         
     }

     for(int i = 0;i<q;i++){
         int x1,x2;
         cin >> x1 >> x2;
         if(levels[x1] < levels[x2]){
             swap(x1,x2);
         }

         int y1 = x1 ,y2 = x2;

         while(levels[y1]!= levels[y2]){
             ll p = log2(levels[y1]- levels[y2]);
             y1 = dp[y1][p];
         }


         if(y1 == y2){
             cout << levels[x1] - levels[x2] << "\n";
             continue;
         }

         while(dp[y1][0] != dp[y2][0]){
            int i = 0;

            for(i = 0;i+1<lim;i++){
                if(dp[y1][i+1] == dp[y2][i+1]){
                    break;
                }
            }

            y1 = dp[y1][i];
            y2 = dp[y2][i];

         }

         int levAnc = levels[dp[y1][0]];

         cout << levels[x1] + levels[x2] - 2*levAnc << "\n";


        
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