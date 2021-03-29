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


class DSU{
    private:
    ll n;
    ll components;
    vector<ll> parent;
    vector<ll> size_g;
    ll largest_comp;
    public:
    DSU(): n(0), components(0),largest_comp(1){}

    DSU(ll size): n(size),components(size), largest_comp(1){
        parent.resize(n+1);
        size_g.resize(n+1,1);
        for(int i = 1;i<=n;i++){
            parent[i] = i;
        }
    }

    ll root(ll x){
        if(parent[x]!=x){
            parent[x] = root(parent[x]);
        }
        return parent[x];
    }


    bool connected(ll x, ll y){
        root(x);
        root(y);
        return parent[x] == parent[y];
    }

    ll getComponents(){
        return components;
    }

    ll getMax(){
        return largest_comp;
    }

    void connect(ll x, ll y){
        if(connected(x,y)){
            return;
        }

        if(size_g[root(x)] < size_g[root(y)]){
            size_g[root(y)]+=size_g[root(x)];
            parent[root(x)] = root(y);
            root(x);
            root(y);
        }
        else if(size_g[root(x)] > size_g[root(y)]){
            size_g[root(x)]+=size_g[root(y)];
            parent[root(y)] = root(x);
            root(x);
            root(y);
        }

        else{
            size_g[root(x)]+=size_g[root(y)];
            parent[root(y)] = root(x);
            root(x);
            root(y);
        }
        components--;
        // DEBUG(x);
        // DEBUG(y);
        // DEBUG(root(x));
        // DEBUG(root(y));
        // DEBUG(size_g[root(x)]);
        // DEBUG(size_g[root(y)]);
        largest_comp = max(largest_comp,size_g[root(x)]);
        largest_comp = max(largest_comp,size_g[root(y)]);
    }
};
void solve(){

    ll n , m;
    cin >> n >> m;

    DSU graph = DSU(n);

    REP(i,m){
        ll a , b;
        cin >> a >> b;
        graph.connect(a,b);
        cout << graph.getComponents() << " " << graph.getMax() << "\n";
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
//   cin >> t; 
   while(t--){
       solve();
   }
}