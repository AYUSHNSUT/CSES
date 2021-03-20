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


void solve(){

    int m , n;
    cin>> n >> m;
    unordered_map<int,int> mpp;
    vvi a(n,vi(m,-3));

    int countt=0;
    REP(i, n){
        string s;
        cin >> s;
        REP(j,m){
            char c = s[j];

            if(c=='#'){
                a[i][j] = 0;
            }
            if(c == '.'){ 
                mpp[i*m + j] = countt++;
                a[i][j] = 1;
            }
        }
    }

    vvi G(countt);

 
    int iter = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){

            if(a[i][j] == 0 ){
                continue;
            }

            // cerr << i << " " << j << "\n";
            if(i<n-1 && a[i+1][j]){

               
                // cerr << "Connecting " << mpp[i*m + j] << "and " << mpp[(i+1)*m + j] << "\n";;
                
                G[mpp[i*m + j]].pb(mpp[(i+1)*m + j]);
                 G[mpp[(i+1)*m + j]].pb(mpp[i*m + j]);

               
            }

               if(j<m-1 && a[i][j+1]){
                 //  cerr << "Connecting " << mpp[i*m + j] << "and " << mpp[i*m+j+1] << "\n";;
                
                G[mpp[i*m + j]].pb(mpp[i*m+j+1]);
                 G[mpp[i*m+j+1]].pb(mpp[i*m + j]);
            }

            //   for( auto r : G[mpp[i*m + j]]){
            //          DEBUG(r);
            //      }
        }
    }

    vi visited(countt);
    queue <int> q;
    int starters = 1;
    for(int i = 0;i<countt;i++){
      //  DEBUG(i);
        if(!visited[i]){
            q.push(i);
            visited[i] = starters;
            // cerr << i << "visited\n";

            while(!q.empty()){
                int testnode = q.front();
                for(auto nodes : G[testnode]){
                if(!visited[nodes]){
                    visited[nodes] = starters;
                    // cerr << nodes << "visited\n";
                    q.push(nodes);
                }
                }
                    q.pop();
            }

            starters++;
        }
    }

    cout << starters - 1 << endl;
  
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