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
// ll dp[1000006];
// int N = 0;

// ll find(ll n, vector <vector <char>> &a){
//     ll row = n/N;
//     ll col = n%N;


//     if(a[row][col] == '*'){
//         return 0;
//     }

//     if(dp[n]!= 0){
//         return dp[n]%M;
//     }

    

//     if(row == 0){
//         dp[n] +=  find(n-1,a)%M;
//     }

//     else if(col == 0){
//         dp[n] +=  find(n-N,a)%M;
//     }

//     else{
//         dp[n] += find(n-1,a)%M + find(n-N,a)%M;
//     }


//     // DEBUG(row);
//     // DEBUG(col);
//     // DEBUG(dp[n]);

//     return dp[n]%M;
    
// }

void solve(){
    ll n;
    cin >> n;
    vector <vector <char>> a(n , vector <char>(n));

    REP(i,n){
        REP(j,n){
            cin >> a[i][j];
        }
    }
    ll dp[1000005];

    memset(dp, 0 , sizeof(dp));

    dp[0] = a[0][0] == '.' ? 1 : 0;

    for(int i = 1;i<n;i++){
        if(a[0][i] == '*'){
            dp[i] = 0;
        }
        else{
            dp[i] += dp[i-1];
        }
    }

     for(int i = 1;i<n;i++){
        if(a[i][0] == '*'){
            dp[i*n] = 0;
        }
        else{
            dp[i*n] += dp[i*n - n];
        }
    }

    for(int row = 1;row<n;row++){
        for(int col = 1;col < n;col++){

            int point = row*n + col;
            if(a[row][col] == '*'){
                dp[point] = 0;
            }
            else{
                dp[point]+=dp[(row-1)*n + col]%M + dp[row*n + col -1]%M;
                dp[point] = dp[point]%M;
            }
            
        }
    }

    cout << dp[n*n - 1]%M << endl;

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