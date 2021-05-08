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
vl vis;
vl subtreeSize;
vl levels;
vl subtreeDownAns;
vl finans;

ll dfsd(ll source, ll parent){
    
    int adj=0;
    for(auto child : G[source]){
        if(child!= parent){
            adj++;
        }
    }
    if(!adj){
        subtreeSize[source]  = 1;
        return 1;
    }

    for(auto child : G[source]){
        if(child!=parent){
            subtreeSize[source] +=dfsd(child,source);
        }
    }
    return subtreeSize[source];
}

ll subtreeAns(ll source, ll parent){

       
    int adj=0;
    for(auto child : G[source]){
        if(child!= parent){
            adj++;
        }
    }

    if(!adj){
        return 0;
    }

    for(auto child : G[source]){
        if(child != parent){
            subtreeDownAns[source] += subtreeAns(child,source) + subtreeSize[child];
        }
    }

    return subtreeDownAns[source];
}

void in_out_dp(ll source, ll parent, ll inheritedAns){

    vector <ll> childList;
    vector <ll> inheritenz;
    // DEBUG(source);
    // DEBUG(inheritedAns);
    
    // if(source == 3){
    //     exit(1);
    // }

    for(auto child : G[source]){
        if(child!= parent){
            childList.pb(child);
            inheritenz.pb(subtreeDownAns[source] - subtreeDownAns[child] - subtreeSize[child]);
        }
    }

    for(int i = 0;i<childList.size();i++){
        ll child = childList[i];
        in_out_dp(child, source, inheritenz[i]);
    }

    if(source == parent){
        return ;
    }


    finans[source] = subtreeDownAns[source] + inheritedAns + (subtreeSize[parent] - subtreeSize[source]);

}



void bfs(ll source, ll parent, ll inheritedAns){

    unordered_map <ll,ll> prnt;
    unordered_map <ll,ll> inher;
    // if(source == 3){
    //     exit(1);
    // }

    queue <ll> Q;

    finans[1] = subtreeDownAns[1];
    for(auto child : G[source]){
        if(child!= parent){
           // DEBUG(child);
           prnt[child] = source;
           //DEBUG(prnt[child]);
           inher[child] = finans[source] - subtreeDownAns[child] - subtreeSize[child];
           Q.push(child);
        }
    }
    while(!Q.empty()){
        ll curr = Q.front();
        // DEBUG(curr);
        Q.pop();
        finans[curr] = subtreeDownAns[curr] + inher[curr] + (subtreeSize[source] - subtreeSize[curr]);
        // DEBUG(finans[curr]);
        for(auto childr : G[curr]){
            if(childr != prnt[curr]){
             //   DEBUG(childr);
                prnt[childr] = curr;
                inher[childr] = finans[curr] - subtreeDownAns[childr] - subtreeSize[childr];
                 Q.push(childr);
        }
        }
    }
}

void solve(){
    ll n;
    cin >> n;

    G.resize(n+1);
    vis.resize(n+1);
    subtreeSize.resize(n+1,1);
    subtreeDownAns.resize(n+1);
    finans.resize(n+1);

    for(int i = 0;i<n-1;i++){
        ll a , b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfsd(1,0);

    subtreeAns(1,0);
    bfs(1,0,0);
    // for(int i = 1;i<=n;i++){
    //     cout << subtreeSize[i] << " ";
    // }
    // cout << endl;

    //    for(int i = 1;i<=n;i++){
    //     cout << subtreeDownAns[i] << " ";
    // }
    // cout << endl;
    for(int i = 1;i<=n;i++){

        cout << finans[i] << " ";
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