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
int m, n;
int getx(int n ){
    return n/m;
}
 
int gety(int n ){
    return n%m;
}
 



void solve(){

    cin>> n >> m;
    unordered_map<int,int> mpp;
    unordered_map <int,int> inverse;
    vvi a(n,vi(m,-3));
    int start, end;

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
                inverse[countt-1] = i*m + j;
                a[i][j] = 1;
            }

            if(c=='A'){
                a[i][j] = 1;
                mpp[i*m + j] = countt++;
                inverse[countt-1] = i*m + j;
                start = countt-1;
            }
            if(c=='B'){
                a[i][j] = 1;
                mpp[i*m + j] = countt++;
                inverse[countt-1] = i*m + j;
                end = countt-1;
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

    vi visited(countt,-1);
    queue <int> q;
     q.push(start);
     visited[start] = start;
            // cerr << i << "visited\n";
    int found = 0;
    while(!q.empty() && !found){
        int testnode = q.front();
        for(auto nodes : G[testnode]){
            if(nodes == end){
                found = 1;
            }
            if(visited[nodes] == -1){
                visited[nodes] = testnode;
                q.push(nodes);
            }
        }
        q.pop();
    }

    if(visited[end]==-1){
        cout << "NO\n";
        return;
    }

    vi path;

    int node = end;

    while(visited[node]!=node){
        path.push_back(node);
        node = visited[node];
    }

    reverse(all(path));
    cout << "YES\n";

    cout << path.size() << "\n";
    vector <char> ans;
    int sX = getx(inverse[start]);
    int sY = gety(inverse[start]);
    for(auto z : path){
        int tX = getx(inverse[z]);
        int tY = gety(inverse[z]);

        // DEBUG(tX);
        // DEBUG(tY);

        if(tX > sX){
            ans.pb('D');
        }
        if(tX < sX){
            ans.pb('U');
        }
        if(tY > sY){
            ans.pb('R');
        }
        if(tY < sY){
            ans.pb('L');
        }

        sX = tX;
        sY = tY;
    }

    for(auto k : ans){
        cout << k;
    }

    return;
    
  
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