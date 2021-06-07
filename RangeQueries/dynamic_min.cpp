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


class segmentMin{
    ll n;
    vl t;

    void makeTree(vl &a , ll v, ll tl , ll tr){
        if(tl > tr) return;
        if(tl == tr){
            // DEBUG(v);
            // DEBUG(tl);
            // DEBUG(a[tl]);
            t[v] = a[tl];
            return;
        }

        ll tm = (tl + tr) / 2;
        makeTree(a,2*v, tl, tm);
        makeTree(a,2*v + 1, tm + 1, tr);
        t[v] = min(t[2*v], t[2*v + 1]);
        // DEBUG(v);
        // DEBUG(t[v]);
        // DEBUG(tl);
        // DEBUG(tr);
    }

       ll findMin(ll v, ll tl , ll tr, ll a, ll b){
        if(a>b || tl > b || tr < a){
            return LLONG_MAX;
        }

        if(a== tl && b == tr){
            return t[v];
        }

        ll tm = (tl + tr) / 2;
        return min(findMin(2*v,tl, tm , a, min(b, tm)),findMin(2*v+1,tm+1, tr , max(a,tm+1), b) );
    }

    void updateNodez(ll v, ll tl, ll tr, ll pos, ll newVal){
        if(tl > tr) return;

        if(tl == tr){
            t[v] = newVal;
            return;
        }

        ll tm = (tl + tr) / 2;

        if(pos <= tm){
            updateNodez(2*v, tl, tm, pos,newVal);
        }
        else{
            updateNodez(2*v + 1, tm + 1, tr, pos,newVal);
        }

        t[v] = min(t[2*v], t[2*v+1]);
    }
    public:
    segmentMin(ll n) : n(n){
        t.resize(4*n, LLONG_MAX);
    }

    void generate(vl &a){
        ll v = 1;
        makeTree(a,v,0,n-1);

        // REP(i,4*n){
        //     DEBUG(i);
        //     DEBUG(t[i]);
        // }
    }

    ll getMin(ll a , ll b){
        return findMin(1,0,n-1,a,b);
    }

    void update(ll pos, ll newVal){
        ll tl = 0;
        ll tr = n-1;
        updateNodez(1,tl,tr,pos, newVal);
    }
 


};
void solve(){
    ll n ,q;
    cin >> n>>q;
    vl a(n);
    REP(i,n){
        cin >> a[i];
        // DEBUG(a[i]);
    }

    segmentMin S(n);
    S.generate(a);

    REP(i,q){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a==1){
            S.update(b-1,c);
        }
        else{
            cout << S.getMin(b-1,c-1) << "\n";
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
//    cin >> t; 
   while(t--){
       solve();
   }
}