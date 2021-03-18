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


ll dp[20][10][2][2];
ll dpsolve(string num , int iter , int lastdigit, int leading_zeroes ,int tight){
    if(iter == 0){
        return 1;
    }

    if(dp[iter][lastdigit][leading_zeroes][tight] != -1){
        return dp[iter][lastdigit][leading_zeroes][tight];
    }

    int lower_bound_of_trying = 0;
    int upper_bound_of_trying = tight == 0? 9 : num[num.size() - iter ] - '0';
    ll tans = 0;
    for(int i = lower_bound_of_trying ; i <= upper_bound_of_trying;i++){
        if(i== lastdigit && !leading_zeroes ){
            continue;
        }
        tans += dpsolve(num , iter - 1 , i , (i== 0 && leading_zeroes)? 1 : 0 , tight && (i == upper_bound_of_trying));
    }

      dp[iter][lastdigit][leading_zeroes][tight] = tans;
      return dp[iter][lastdigit][leading_zeroes][tight];

}

void solve(){
    ll a , b;
    cin >> a >> b;
    string A , B;
    A = to_string(a-1);
    B = to_string(b);

   // cout << A << endl << B << endl;
  //  cerr << dpsolve(B, B.size(), -1 , 1, 1) << endl;
   // cerr << dpsolve(A, A.size(), -1 , 1, 1) << endl;
   memset(dp , -1 ,sizeof(dp));
   ll ans1 = dpsolve(B, B.size(), -1 , 1, 1);
    memset(dp , -1 ,sizeof(dp));
    ll ans2 =  dpsolve(A, A.size(), -1 , 1, 1) ;

    cout << ans1 - ans2 << endl;

    
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