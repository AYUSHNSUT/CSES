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

ll node(ll x , ll y){
    return (x-1)*8 + y-1;
}

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

bool isValid(ll x , ll y){
    return x>=1 && x<=8 && y>=1 && y<=8;
}

void dfs(ll source, ll &found, vvl &G, vl &done, vl &path){
    if(found == 64) return;

    
}
void solve(){
    ll x , y;
    cin >> x >> y;

    vvl G(64);

    vl outdegree(64);

    for(int xx = 1;xx<=8;xx++){
        for(int yy = 1;yy<=8;yy++){
            for(int i = 0;i<8;i++){
                if(isValid(xx + dx[i], yy +dy[i])){
                    G[node(xx,yy)].pb(node(xx + dx[i], yy +dy[i]));
                    outdegree[node(xx,yy)]++;
                }
            }
        }
    }

    vl done(64);
    ll start = node(x,y);
    done[node(x,y)] = 1;
    ll found = 1;
    vl path;

    dfs(start, found, G, done, path);

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