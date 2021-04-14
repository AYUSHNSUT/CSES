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
vl indegree;
ll n , m;

ll transform(ll x, ll y){
    return (x-1)*n + y;
}
void solve(){
   
    cin >> n >> m;
    G.resize(n+1);
    unordered_map <ll,ll> mat;
    vl indegree(n+1);
    indegree.resize(n+1);
    REP(i,m){
        ll a , b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
        mat[transform(a,b)]++;
        mat[transform(b,a)]++;
        indegree[a]++;
        indegree[b]++;
    }

    for(int i  = 1;i<=n;i++){
        // if(indegree[i]%2 && i == 1){
        //     checc = true;
        // }

        // else if(indegree[i]%2 ){
        //     if(checc){
        //         checc = false;
        //         change = true;
        //         second = i;
        //     }
        //     else{
        //     }
        // }

            // DEBUG(indegree[i]);
        if(indegree[i]%2||(indegree[i]==0 && i==1)){
                cout << "IMPOSSIBLE\n";
                return;
        }
    }

 
    
    vl curr_path;
    vl final_circuit;

    ll curr = 1;
    curr_path.pb(curr);
    ll mm = 0;
    while(!curr_path.empty()){
        // DEBUG(curr);
        // DEBUG(G[curr].size());
        if(!G[curr].empty()){
           ll next = G[curr].back();
        //    DEBUG(next);  
        //    DEBUG(transform(curr,next));
        //    DEBUG(mat[transform(curr,next)] );
        }
      //  DEBUG(mm);
        if(!G[curr].empty() && !mat[transform(curr,G[curr].back())] ){
            G[curr].pop_back();
            continue;
        }
        if(!G[curr].empty()){
            curr_path.pb(curr);
            ll next = G[curr].back();
            G[curr].pop_back();
            mat[transform(curr,next)]--;
            mat[transform(next,curr)]--;;
            mm++;
            curr = next;
        }
        else{
            // cerr << "REMOVAL\n";
            // DEBUG(curr);
            final_circuit.pb(curr);
            if(!curr_path.empty()){
                curr = curr_path.back();
            }
            curr_path.pop_back();
            // cerr << "BACKTRACK " << curr<< "\n";
            // for(auto k : final_circuit){
            //     cerr << k << " ";
            // }
        }
    }

    if(mm != m){
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(all(final_circuit));
    for(auto k: final_circuit){
        cout << k << " ";
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