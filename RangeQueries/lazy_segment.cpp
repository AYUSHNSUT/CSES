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


class segmentSumLazy{
    ll n;
    vl t;
    vl lazy;
    void makeTree(vl &a , ll v, ll tl , ll tr){
        if(tl > tr) return;
        if(tl == tr){
            t[v] = a[tl];
            return;
        }

        ll tm = (tl + tr) / 2;
        makeTree(a,2*v, tl, tm);
        makeTree(a,2*v + 1, tm + 1, tr);
        t[v] = t[2*v]+ t[2*v + 1] ;
    }

       ll findSum(ll v, ll tl , ll tr, ll a, ll b){
        if(a>b || tl > b || tr < a){
            return 0;
        }
        if(lazy[v]){
            t[v] += (tr - tl + 1) * lazy[v];

            if(tl!= tr){
                lazy[2*v] += lazy[v];
                lazy[2*v+1] += lazy[v];
            }
        }

        lazy[v] = 0;

        if(a== tl && b== tr){
            return t[v];
        }

        ll tm = (tl + tr) / 2;
        return findSum(2*v,tl, tm , a, min(b, tm))+findSum(2*v+1,tm+1, tr , max(a,tm+1), b) ;
    }

    void updateNodez(ll v, ll tl, ll tr, ll a, ll b, ll newVal){
        if(tl > tr) return;
        // DEBUG(v);
        // DEBUG(tl);
        // DEBUG(tr);
       if(lazy[v]){
           t[v] += (tr - tl + 1) * lazy[v];

           if(tl != tr){
               lazy[2*v] += lazy[v];
               lazy[2*v+1] += lazy[v];
           }
       }
       lazy[v] = 0;
       
       if(tl >b || tr < a) return;
       if(a <= tl && b >= tr){
           t[v] += (tr - tl + 1) * newVal;

           if(tl != tr){
               lazy[2*v] += newVal;
               lazy[2*v + 1] += newVal; 
           }

           return;
       }

       ll tm = (tl + tr) / 2;
       updateNodez(2*v, tl ,tm , a,b,newVal);
       updateNodez(2*v + 1 , tm+1, tr , a,b,newVal);

       t[v] = t[2*v] + t[2*v + 1];

    
    }
    public:
    segmentSumLazy(ll n) : n(n){
        t.resize(4*n);
        lazy.resize(4*n);
    }

    void generate(vl &a){
        ll v = 1;
        makeTree(a,v,0,n-1);

        // REP(i,4*n){
        //     DEBUG(i);
        //     DEBUG(t[i]);
        // }
    }

    ll getSum(ll a , ll b){
        return findSum(1,0,n-1,a,b);
    }

    void update(ll a, ll b, ll newVal){
        ll tl = 0;
        ll tr = n-1;
        updateNodez(1,tl,tr,a,b, newVal);
    }
 


};
void solve(){
    ll n,q;
    cin >> n >> q;

    vl a(n);

    REP(i,n){
        cin >> a[i];
    }

    segmentSumLazy SL(n);
    SL.generate(a);

    REP(i,q){
        ll a ;
        cin >> a;
        // DEBUG(a);
        if(a== 2){
            ll k;
            cin >> k;
            cout << SL.getSum(k-1,k-1) << endl;
        }
        else{
            ll b,c,d;
            cin >> b >> c >> d;
            SL.update(b-1,c-1,d);
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
   //cin >> t; 
   while(t--){
       solve();
   }
}