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
vl enter;
vl leave;
ll timer = 0;


class FT{
    ll n;
    vl tree;
    public:
        FT(ll n) : n(n){
            tree.resize(n+2);
        }

    void add(ll pos,ll x){
        while(pos <= n ){
            tree[pos]+=x;
            pos+= pos&(-pos);
        }

    }

    ll sum(ll point){
        ll res = 0;
       // DEBUG(point);

     
        if(!point) return 0;
        while(point >= 1){
        //    DEBUG(point);
            res += tree[point];
            point -= point & (-point);
        }
        return res;
    }
};

void dfs(ll source, ll parent){
  //  DEBUG(source)
    enter[source] = timer++;

    for(auto child: G[source]){
        if(child^parent){
            dfs(child,source);
        }
    }
    leave[source] = timer-1;
}
void solve(){
    ll n,q;
    cin >> n >> q;

    G.resize(n+1);
    vals.resize(n+1);
    enter.resize(n+1);
    leave.resize(n+1);

    REP(i,n){
        cin >> vals[i+1];
    }

    for(int i = 0;i<n-1;i++){
        ll a , b;
        cin >> a >>b;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(1,0);

    FT f(n);

    for(int i= 1;i<=n;i+=1){
        //DEBUG(i);
        enter[i]++;
        leave[i] ++ ;
        f.add(enter[i], vals[i]);
        f.add(leave[i]+1, -vals[i]);
    }

    REP(i,q){
        ll query;
        cin >> query;
       // DEBUG(query);

        if(query == 1){
            ll s , x;
            cin >> s >> x;
            ll prevVal = vals[s];

            f.add(enter[s], x-vals[s]);
            f.add(leave[s] + 1, -(x-vals[s]));
            vals[s]= x;
        }

        else{
            ll s;
            cin >> s;
            cout << f.sum(enter[s]) << endl;
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