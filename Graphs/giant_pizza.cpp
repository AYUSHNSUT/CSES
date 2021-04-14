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
vl vis, ivis;
vl stronk;
vvl G, iG;
stack <ll> order;
ll n, m;

void dfs(int n){
    vis[n] = 1;
    // DEBUG(n);
    for(auto child : G[n]){
        if(!vis[child]){
            dfs(child);
        }
    }

    stronk.pb(n);
    vis[n] = 2;
}


void idfs(int n){
    ivis[n] = 1;
    // DEBUG(n);
    for(auto child : iG[n]){
        // DEBUG(child);
        if(!ivis[child]){
            idfs(child);
        }
    }
    
    order.push(n);
    ivis[n] = 2;
}

ll complement_node(ll x){
    return (x + m)%(2*m);
}

void solve(){

 
    cin >> n >> m;
    DEBUG(n);
    DEBUG(m);

    G.resize(2*m);
    iG.resize(2*m);

    vis.resize(2*m);
    ivis.resize(2*m);

    vector <ll> done(2*m);
    REP(i,n){
        char s1,s2;
        ll x1 , x2;
        cin>> s1 >> x1 >> s2 >> x2;
        x1--;
        x2--;
        // DEBUG(s1);
        // DEBUG(s2);
        
        if(s1 == '-'){
            x1 = complement_node(x1);
        }
        if(s2 == '-'){
            x2 = complement_node(x2);
        }
        //   DEBUG(x1);
        // DEBUG(x2);
        G[complement_node(x1)].pb(x2);
        G[complement_node(x2)].pb(x1);

        iG[x2].pb(complement_node(x1));
        iG[x1].pb(complement_node(x2));
    }

    //   REP(i,2*m){
    //       DEBUG(i+1);
    //     for(auto node : G[i]){
    //         DEBUG(node+1);
    //     }

    //     cerr <<"*******\n";
    // }


    for(int i = 1;i<2*m;i++){
         if(!ivis[i]) idfs(i);
    }
    vvl strongly;
    while(!order.empty()){
        ll z = order.top();
        // DEBUG(z+1);
        order.pop();

        if(!vis[z]){
            dfs(z);
            
            unordered_map <ll,ll> hashh;

            // for(auto k: stronk){
            //     DEBUG(k+1);
            // }
            // cerr << "\n***********\n";
            for(auto k : stronk){
                hashh[k] = 1LL;
                if(hashh[complement_node(k)]){
                    cout << "IMPOSSIBLE\n";
                    return;
                }
            }

            strongly.pb(stronk);
            stronk.clear();
        }
       
    }
     for(auto stronks : strongly){
            for(auto node : stronks){
                // DEBUG(node+1);
                // DEBUG(complement_node(node)+1);
                if(!done[node]){
                        done[node] = 2;
                        done[complement_node(node)] = 1;
                }
            }
            // cerr << "\n***********\n";
        }

     for(ll i = 0;i<m;i++){
        //  DEBUG(i);
        //  DEBUG(done[i]);
            if(done[i] == 2){
                cout << "+ ";
            }
            else{
                cout << "- ";
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