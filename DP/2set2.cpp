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
ll dp[502][125252];

ll findSums(int n , ll s){
    if( n<0 || s< 0){
        return 0;
    }


    if(dp[n][s]!= -1){
        return dp[n][s];
    }

    dp[n][s] = (findSums(n-1 , s - n)%M + findSums(n-1 , s)%M)%M;
    // cerr << n << " " << s << endl;
    // DEBUG(dp[n][s]);
    return dp[n][s];
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    ll s = 0;
    // REP(i,n){
    //     cin >> a[i];
    //     s+=a[i];
    // }

    s = n * (n+1);
    s/=2;
    if(s%2){
        cout << 0 << endl;
        return;
    }

    memset(dp , -1 ,sizeof(dp));

    for(int i = 1;i<= n;i++){
        dp[i][0] = 1;
    }

    for(int i = 0;i<=s;i++){
        dp[0][i] = 0;
    }

    cout <<  findSums(n , s/2)%M << endl;

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