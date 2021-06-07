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
        t[v] = t[2*v]+ t[2*v + 1] ;
    }

       ll findSum(ll v, ll tl , ll tr, ll a, ll b){
        if(a>b || tl > b || tr < a){
            return 0;
        }

        if(a== tl && b == tr){
            return t[v];
        }

        ll tm = (tl + tr) / 2;
        return findSum(2*v,tl, tm , a, min(b, tm))+findSum(2*v+1,tm+1, tr , max(a,tm+1), b) ;
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

        t[v] = t[2*v]+ t[2*v+1];
    }
    public:
    segmentSum(ll n) : n(n){
        t.resize(4*n);
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

    void update(ll pos, ll newVal){
        ll tl = 0;
        ll tr = n-1;
        updateNodez(1,tl,tr,pos, newVal);
    }
 


};

class HeavyLight{
    ll n;
    vvl G;
    vl heavy;
    vl vals;
    vvl dp;
    vl head;
    vl subtreeSize;
    vl depth;
    vl occur, occuri;

    ll timer;
    public:

    HeavyLight(ll k, vvl &G){

        k = n;
        timer = 0;
        heavy.resize(n+1);
        vals.resize(n+1);
        dp.resize(n+1,vl(20));
        head.resize(n+1);
        subtreeSize.resize(n+1,1);
        depth.resize(n+1);
        depth[0] = -1;
        occur.resize(n+1);
        occuri.resize(n+1);


         REP(i,n){
             cin >> vals[i+1];
     }


     REP(i,n-1){
         ll a , b;
         cin >>a >> b;
         G[a].pb(b);
         G[b].pb(a);
     }

     dfs(1,0);
     decompose(1,1);
     segmentMax S(n);
     vector <ll> arr(n);
    unordered_map <ll,ll> head_c;
     for(int i = 0;i<n;i++){
         arr[i] = vals[occuri[i]];
         ll hd = head[occur[i]];
         head_c[hd]++;
     }

     S.generate(arr);
    }

    void dfs(ll source,ll parent){
        ll mxchild = -1;
        dp[source][0] = parent;
        depth[source] = depth[parent] + 1;
        for(auto child :G[source]){
            if(child ^ parent){
                dfs(child,parent);
                subtreeSize[source] += subtreeSize[child];

                if(subtreeSize[child] > mxchild){
                    mxchild = subtreeSize[child];
                    heavy[source] = child; 
                }
            }
        }
    }

    void decompose(ll source, ll head_g){
        head[source] = head_g;
        occur[source]  = timer++;
        occuri[timer-1] = source;

        if(heavy[source]!= -1){
            decompose(heavy[source],head_g);
        }
        for(auto child : G[source]){
            if(child ^ dp[source][0] && child != heavy[source]){
                decompose(child, child);
            }
        }
    }

};

void solve(){
    ll n,q;
    cin >> n >> q;
    vl vals(n+1);

   
    vvl G;
    G.resize(n+1);

    HeavyLight HV(n,G);
}





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
   cin >> t; 
   while(t--){
       solve();
   }
}