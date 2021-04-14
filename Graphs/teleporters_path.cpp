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
ll n , m;

ll transform(ll a, ll b){
    return (a-1)*n + b;
}

// void dfs(vvl &G, unordered_map<ll,ll> &visited, int source){
//     visited[source] = 1;

//     for(auto child : G[source]){
//         if(!visited[child]){
//             dfs(G,visited,child);
//         }
//     }
// }
// bool reachable(vvl &G){
//     ll start  = 1;
    
//     unordered_map <ll,ll> visited;

//     dfs(G,visited,1);
//     DEBUG(visited.size());
//     if(visited.size() == n){
//         return true;
//     }
//     return false;
// }

void solve(){
   
    cin >> n >> m;

    vvl G(n+1);
    vl indegree(n+1);
    vl outdegree(n+1);
      if(n==1){
        cout << "10" << endl;
        return;
    }
    REP(i,m){
        ll a , b;
        cin >> a >> b;
        G[a].pb(b);
        indegree[b]++;
        outdegree[a]++;
    }

    for(int i = 1;i<=n;i++){
        // DEBUG(indegree[i]);
        // DEBUG(outdegree[i]);
        if(i == 1){
            if(outdegree[i] - indegree[i] != 1){
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
        else if(i == n){
            if(outdegree[i] - indegree[i] != -1){
                cout << "IMPOSSIBLE\n";
                return;
            }
        }

        else{
            if(indegree[i]!=outdegree[i]){
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }



    ll curr = 1;
    vl curr_path, final_circuit;

    curr_path.pb(curr);
    ll edgez = 0;
    while(!curr_path.empty()){
        // DEBUG(curr);
        if(!G[curr].empty()){
            ll next = G[curr].back();
            G[curr].pop_back();
            edgez++;
            curr_path.pb(next);
            curr = next;
        }
        else{
            final_circuit.pb(curr);
            if(!curr_path.empty()){
                curr_path.pop_back();
                if(!curr_path.empty())
                curr = curr_path.back();
            }
        }
    }

    reverse(all(final_circuit));

    if(edgez!=m){
         cout << "IMPOSSIBLE\n";
         return;
    }
    for(auto l: final_circuit){
        cout << l << " ";
    }
    vl finc;
    bool hogaya = false;
    // for(int i = 0;i<final_circuit.size()-1 && !hogaya;i++){
    //     if(final_circuit[i] == n && final_circuit[i+1]==1){
    //         for(int z = i+1;z<final_circuit.size();z++){
    //             finc.pb(z);
    //         }
    //          for(int z = 0;z<=i;z++){
    //             finc.pb(z);
    //         }
    //         hogaya = true;
    //     }
    // }
    
    // for(auto k : finc){
    //     cout << k << " ";
    // }
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