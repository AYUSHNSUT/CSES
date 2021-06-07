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

class segmentSum{
    ll n; vl t;


    ll findSum(ll v,ll tl, ll tr, ll l , ll r){
        // DEBUG(v);
        // DEBUG(tl);
        // DEBUG(tr);
        // DEBUG(l);
        // DEBUG(r);
        if(l>r || tl > r || tr < l) return 0;

        if(tl == l && tr == r){
            return t[v];
        }

        ll tm = (tl + tr) /2 ;
        return findSum(2*v , tl , tm , l, min(tm, r)) + findSum(2*v+1 , tm+1, tr , max(l, tm+1), r);
    }

    ll updateOne(ll v, ll tl, ll tr, ll pos, ll newVal){
        if(tl == tr){
            t[v] = newVal;
        }
        else {
            ll tm = (tl + tr) / 2;
            if(pos <= tm){
                updateOne(2*v, tl, tm ,pos, newVal);
            }
            else{
                updateOne(2*v+1, tm+1, tr, pos,newVal);
            }
            t[v] = t[2*v] + t[2*v+1];
        }
        return t[v];
    }

       ll generate_tree(vl &a , ll v, ll tl, ll tr){
        if(tl == tr){
            t[v] = a[tl];
        }
        else{
            ll tm = (tl + tr) / 2;
            ll al = generate_tree(a,2*v,tl,tm);
            ll ar = generate_tree(a,2*v + 1 , tm+1 , tr);
            t[v] = t[2*v] + t[2*v + 1];
        }
        // cout << v << " " << t[v] << endl;
        return t[v];
    }

    public:
    segmentSum(ll n) : n(n)  {
        t.resize(4*n);
    }
    void createSegment(vl &a){
        ll v = 1;
        generate_tree(a,v,0,n-1);
        //    for(int i = 0;i<4*n;i++){
        //     cout << i << " "<< t[i] << endl;
        // }
    }

    ll find(ll a, ll b){
        // DEBUG(a);
        // DEBUG(b);
        return findSum(1,0,n-1,a,b);
    }

    void update(ll pos, ll newVal){
        updateOne(1,0,n-1,pos,newVal);
    }



};
void solve(){
    ll n , q;
    cin >> n >> q;

    vl a(n);

    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    
    segmentSum S(n);
    S.createSegment(a);
    REP(i,q){
        ll a , b;
        cin >> a >> b;
        cout << S.find(a-1,b-1) << "\n";
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