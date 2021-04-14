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
inline void unset_bit(ll & n, ll b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
#define fast_cin() std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////



void solve(){
    ll n;
    cin >> n;
    // DEBUG(n);
    ll t = n-1;

    vector <vector <pll>> G(1<<t);
  
    for(int i = 0;i<1<<t;i++){
        ll n1 = i & ~(1<<(t-1));
        ll tempnode = n1 << 1;
        // DEBUG(i);
        // DEBUG(tempnode);
        // DEBUG(tempnode+1);
        G[i].pb({tempnode,0});
        G[i].pb({tempnode+1,1});
    }

    string ans = "";

    REP(i,t){
        ans+='0';
    }
    // DEBUG(ans);

    ll curr = 0;
    vl curr_path;
    curr_path.pb(curr);
    vl final_circuit;

    while(!curr_path.empty()){
        // DEBUG(curr);
          if(!G[curr].empty()){
            curr_path.pb(curr);
            ll next = G[curr].back().first;
            // DEBUG(next);
            // DEBUG(G[curr].back().second);
            G[curr].pop_back();
            curr = next;
        }
          else{
            // cerr << "REMOVAL\n";
            // DEBUG(curr);
            final_circuit.pb(curr);
            if(!curr_path.empty()){
                curr = curr_path.back();
                 curr_path.pop_back();
            }
            // cerr << "BACKTRACK " << curr<< "\n";
            // for(auto k : final_circuit){
            //     cerr << k << " ";
            // }
        }
    }

    reverse(all(final_circuit));

    for(int i = 1;i<final_circuit.size();i+=1){
        ll prev = final_circuit[i-1];
        ll n1 = prev & ~(1<<(t-1));
        ll tempnode = n1 << 1;
        
        if(tempnode == final_circuit[i]){
            ans += "0";
        }
        else{
            ans+="1";
        }

    }

    cout << ans << endl;

    
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