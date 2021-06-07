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
vvl G;
vl vals;
vl vis;
vl subtreeSize;
vl dfsTree;

class segmentTree{
    vl t;
    ll n;

    void createTree(ll v, ll l , ll r,vl &a){
        if(l == r){
            // DEBUG(dfsTree[l]);
            t[v] = vals[dfsTree[l]];
        //      DEBUG(l);
        // DEBUG(r);
        // DEBUG(v);
        // DEBUG(t[v]);
            return;
        }

        ll mid = (l+r)/2;

        createTree(2*v,l,mid,a);
        createTree(2*v+1,mid+1,r,a);

        t[v] = t[2*v] + t[2*v+1];
        //  DEBUG(l);
        // DEBUG(r);
        // DEBUG(v);
        // DEBUG(t[v]);
    }

    void update(ll v,ll l, ll r, ll x, ll newVal){
        if(l == r){
            // DEBUG(l);
            t[v] = newVal;
            return;
        }

        int mid = (l+r)/2;
        // DEBUG(mid);
        // DEBUG(x);
        // DEBUG(l);
        // DEBUG(r);
        if(mid >= x){
          //  cerr << "YES\n";
            update(2*v,l,mid,x,newVal);
        }
        else{
            update(2*v+1,mid+1,r,x,newVal);
        }

        t[v] = t[2*v] + t[2*v+1];
       
    }

    ll rangeQuery(ll v, ll l, ll r, ll a, ll b){
        if(a > b){
            return -1;
        }
        if(a<= l && b>=r){
            return t[v];
        }

        if(r < a || l > b){
            return 0;
        }

        ll mid  = (l+r) / 2;

        return rangeQuery(2*v,l,mid,a,b) + rangeQuery(2*v+1,mid+1,r,a,b);
    }
    public :

    segmentTree(ll n) : n(n) {
        t.resize(4*n);
    }

    void makeTree(vl &a){
        int l = 0;
        ll r = a.size()-1;
        createTree(1,0,r,a);
    }

    void updateTree(int x, int newVal,vl&a){
        int l = 0;
        int r = a.size()-1;

        update(1,0,r,x,newVal);
    }

    ll getAns(ll a, ll b){
        return rangeQuery(1,0,n-1,a,b);
    }
};

void dfs(ll curr,ll parent, ll &odr){
    odr++;
    vis[curr] = odr-1;
    // DEBUG(curr);
    // DEBUG(parent);
    for(auto child : G[curr]){
        if(child != parent){
            dfs(child, curr, odr);
            subtreeSize[curr] += subtreeSize[child];
        }
    }
}

void solve(){

    ll n,q;
    cin >> n >> q;
    G.resize(n+1);
    vis.resize(n+1);
    subtreeSize.resize(n+1,1);
    vals.resize(n+1);

    REP(i,n){
        cin >> vals[i+1];;
    }

    REP(i,n-1){
        ll a , b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    ll odr = 0;

     dfs(1,0,odr);
    //    for(int i = 1;i<=n;i++){
    //     DEBUG(i);
    //     DEBUG(vis[i]);
    //     DEBUG(vals[i]);
    // }

    
    dfsTree.resize(n);

    for(int i = 1;i<=n;i++){
        dfsTree[vis[i]] = i;
    }

 
    segmentTree S(n);
    S.makeTree(dfsTree);

    REP(i,q){
        ll x, y;
        cin >> x>> y;
        if(x == 1){
            ll z;
            cin >> z;
            ll actualPos = vis[y];
           // DEBUG(actualPos);
            S.updateTree(actualPos,z,dfsTree);
        }
        else{
            ll actualPost = vis[y];
            // DEBUG(actualPost);
            cout << S.getAns(actualPost,actualPost+subtreeSize[y]-1) << endl;
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

//    for(int i = 1;i<=n;i++){
//         DEBUG(i);
//         DEBUG(vis[i]);
//     }