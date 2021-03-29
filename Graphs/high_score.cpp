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
const ll ninf = -1 * inf;
struct Edge{
    int start;
    int end;
    ll weight;
};


void solve(){
    ll n , m;
    cin >> n >> m;

    vi a(n);
    vector <Edge> edgelist(m);

    REP(i,m){
        cin >> edgelist[i].start >> edgelist[i].end >> edgelist[i].weight;
        edgelist[i].start--;
        edgelist[i].end--;
        edgelist[i].weight*=-1;
    }

    vector <ll> distance(n, (ll)inf);
    distance[0] = 0;

    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<m;j++){
            int u = edgelist[j].start;
            int v = edgelist[j].end;
            ll wt = edgelist[j].weight;

            if(distance[u] == inf){
                continue;
            }

            distance[v] = min(distance[v], distance[u] + wt);
        }
    }

    for(int i = 0;i<n-1;i++){
     for(int j = 0;j<m;j++){
            int u = edgelist[j].start;
            int v = edgelist[j].end;
            ll wt = edgelist[j].weight;

            if(distance[u] == inf){
                continue;
            }

            // distance[v] = min(distance[v], distance[u] + wt);
            // distance[v] = max(ninf, distance[v]);

            if(distance[u] + wt < distance[v]){
                distance[v] = ninf;
            }
        }
    }
        
        if(distance[n-1] == ninf || distance[n-1] == inf){
            cout << -1 << endl;
            return;
        }
        cout << -1 * distance[n-1] << endl;


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
//    cin >> t; 
   while(t--){
       solve();
   }
}