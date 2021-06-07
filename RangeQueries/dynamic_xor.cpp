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

class segmentXor{
    ll n;
    vl t;

    void makeTree(vl &a, ll v, ll tl, ll tr){
        if(tl > tr) return;
  
        if(tl == tr){
            t[v] = a[tl];
            return;
        }

        ll tm = (tl + tr) / 2;
        makeTree(a,2*v,tl,tm);
        makeTree(a, 2*v + 1 , tm+1 , tr);

        t[v] = t[2*v] ^ t[2*v + 1];
        // DEBUG(v);
        // DEBUG(tl);
        // DEBUG(tr);
        // DEBUG(t[v]);
    }

    ll findXor(ll v, ll tl , ll tr, ll a, ll b){
        if(a > b) return 0;
        // DEBUG(tl);
        // DEBUG(tr);
        // DEBUG(a);
        // DEBUG(b);
        if(tl == a && tr == b){
            return t[v];
        }

        ll tm = (tl + tr) / 2;
        return findXor(2*v, tl , tm , a, min(b, tm)) ^ findXor(2*v + 1, tm+1, tr, max(a,tm+1), b);
    }

    void updateTree(ll v, ll tl,ll tr, ll pos , ll newVal){
        if(tl == tr){
            t[v] = newVal;
            return;
        }

        ll tm = (tl + tr) / 2;
        if(pos <= tm){
            updateTree(2*v, tl, tm, pos, newVal);
        }
        else{
            updateTree(2*v + 1, tm+1, tr, pos, newVal);
        }

        t[v] = t[2*v] ^ t[2*v + 1];

    }

    public:
    segmentXor(ll n) : n(n)  {
        t.resize(4*n);
    } 

    void generateTree(vl &a){
       ll tl = 0;
       ll tr = n-1;
       ll v = 1;
        makeTree(a, v, tl, tr);
    }

    ll getXor(ll a, ll b){
        return findXor(1,0,n-1,a,b);
    }

    void update(ll pos, ll newValue){
        updateTree(1,0,n-1,pos,newValue);
    }
};
void solve(){
    ll n , q;
    cin >> n >> q;

    vl a(n);
    REP(i,n){
        cin >> a[i];
    }

    segmentXor X(n);
    X.generateTree(a);

    REP(i,q){
        ll a ,b;
        cin >> a >> b ;
        cout << X.getXor(a-1,b-1) << endl;

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