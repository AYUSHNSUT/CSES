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

class segmentTree{
    ll n; vl t;

    ll Get(ll v, ll tl , ll tr , ll x){
        if(t[v]  < x){
            return -1;
        }

        if(t[v] == x){
            return tr;
        }

        ll tm = (tl + tr) / 2;
        ll tans = Get(2*v,tl,tm,x);
        if(tans!= -1){
            return tans;
        }
        return Get(2*v+1,tm+1, tr, x);
    }

    void updateTree(ll v, ll tl , ll tr , ll idx){
        if(tl > tr) return;

        if(tl == tr){
            t[v] = 0;
            return;
        }

        ll tm = (tl + tr) / 2;

        if(idx <= tm){
            updateTree(2*v, tl, tm,idx);
        }
        else{
            updateTree(2*v + 1, tm + 1, tr,idx);
        }

        t[v] = t[2*v]+t[2*v+1];
    }

    public:
    segmentTree(ll n) : n(n){
        t.resize(n,1);
    }

    ll get(ll x){
        return Get(1,0,n-1,x);
    } 

    void update(ll idx){
        updateTree(1,0,n-1,idx);
    }
};

void solve(){

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