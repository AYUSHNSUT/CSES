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
int dp[100005][102];
int m;
//vector <int> ansaa(10);
int find(vi &a, int x, int prev){
    if(x==a.size()){
        // for(auto k : ansaa){
        //     cout << k << " ";
        // }
        // cout << endl;
        return 1;
    }

    if(prev != 0 && dp[x+1][prev] != -1){
        return dp[x+1][prev];
    }

    int iterans = 0;

    if(prev == 0){
        if(a[x] == 0){
            for(int i = 1;i<=m;i++){
              //  ansaa[x] = i;
                iterans += find(a,x+1,i)%M;
                iterans %=M;
            }
        }
        else{
          //  ansaa[x] = a[x];
            iterans += find(a,x+1,a[x])%M;
            iterans %=M;
        }
    }

    else{

        if(a[x] == 0){
            if(prev > 1){
             //   ansaa[x] = prev-1;
                iterans += find(a, x+1,prev-1 );
                iterans %=M;
            }
           
          //  ansaa[x] = prev;
            iterans += find(a, x+1,prev );
            iterans %=M;

            if(prev < m){
           // ansaa[x] = prev+1;
            iterans += find(a, x+1,prev+1 );
            iterans %=M;

            }
            
        }
        else if(abs(a[x] - prev) > 1){
            return 0;
        }
        else{
          //  ansaa[x] = a[x];
            iterans += find(a,x+1, a[x]);
            iterans %=M;
        }
    }

    dp[x+1][prev] = iterans %M;
    return dp[x+1][prev];
}

void solve(){

    int n;
    cin >> n >> m;

    vi a(n);
    REP(i,n){
        cin >> a[i];
    }
    int ans;

    memset(dp ,-1 , sizeof(dp));
    for(int i = 0;i<=n;i++){
        dp[0][i] == 0;
    }

    for(int i = 0;i<=m;i++){
        dp[0][m] == 0;
    }
    ans = find(a, 0 ,0);
    

    cout << ans %M;



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
//    cin >> t; 
   while(t--){
       solve();
   }
}