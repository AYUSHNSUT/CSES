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
ll ansg = 0;
vvl gans;
void dfs(int source, vvl &G, vl &ind, vl&visited, stack <ll> &S,int &alreadyprint){
   //  DEBUG(source);
    visited[source] = 1;
    S.push(source);

    for(auto child : G[source]){
        // DEBUG(child);
        // DEBUG(visited[child]);
        // DEBUG(alreadyprint);
        ind[child]--;
            if(!visited[child] && !alreadyprint && ind[child] == 0){
                dfs(child,G,ind,visited,S,alreadyprint);
            }
            else if (visited[child] && !alreadyprint){
                alreadyprint = 2;
                cout << "IMPOSSIBLE\n";
                exit(0);
            }       
    }

    if(alreadyprint == 0){
        vl ans;
        while(!S.empty()){
            ans.pb(S.top());
            S.pop();
        }
        reverse(all(ans));
        ansg += ans.size();
        gans.pb(ans);
        // for(auto lambda : ans){
        //     cerr << lambda << " ";
        // }
        // cerr << "\n**************\n";
        alreadyprint = 1;
    }
}

void solve(){

    ll n , m;
    cin >> n >> m;

    vvl G(n+1);
    vvl iG(n+1);
    vl ind(n+1);
    vl out(n+1);
    REP(i,m){
        ll a , b;
        cin >> a >> b;
        // DEBUG(a);
        // DEBUG(b);
        G[a].pb(b);
        iG[b].pb(a);
        ind[b]++;
        out[a]++;
    }

    vl visited(n+1);
    stack <ll> S;
    int alreadyprint = 0;
    int donesome=0;
    while(ansg <n){

        for(int i = 1;i<=n;i++){
        
            if(ind[i] == 0&&!visited[i]){
            //    DEBUG(i);
                donesome++;
                dfs(i,G,ind,visited,S,alreadyprint);
                if(alreadyprint == 1)
                alreadyprint = 0;
                else return;
            }
        }
       // DEBUG(donesome);
        if(donesome == 0){
             cout << "IMPOSSIBLE\n";
                exit(0);
        }
        else{
            donesome = 0;
        }
    }

    for(auto ans : gans){
        for(auto lambda : ans){
            cout << lambda << " ";
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