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


/*

TODO:
1. Iterate through all subsets
2. Store , for each subset, the optimal number rides and the weight of last ride optimally.
3. To add an element, there are two cases , we can either add the element to a previous ride
    if the weight is not full or we can add it to new ride
*/

void solve(){
    ll n , x;
    cin >> n >> x;
    vl wt(n) ;

    REP(i,n){
        cin >> wt[i];
    }

    pair <int,int> dp[1 << n];


    dp[0] = mp(0 , 0);

    for(int m = 1;m< 1<<n;m++){
        //DEBUG(m);
        dp[m] = mp(n+1, 0);
        for(int s = 0;s<n;s++){
            if(m & (1 << s)){
               // cerr << s << endl;
              //  DEBUG(dp[m ^ (1<<s)].first);
                pair <int,int> previousOptimalSolution = dp[m ^ (1<<s)];

                if(previousOptimalSolution.second  + wt[s] <= x){
                    previousOptimalSolution.second += wt[s];
                }
                else{
                    previousOptimalSolution.second = wt[s];
                    previousOptimalSolution.first++;
                }
              //  DEBUG(previousOptimalSolution.first);

                dp[m] = min(dp[m], previousOptimalSolution);
            }

        }
    }

    // for(int i = 0;i< 1<<n;i++){
    //      cout << "i = " << i << endl;
    //      cout << dp[i].first << endl;
    //      cout << dp[i].second << endl;
         
    // }

    cout << dp[(1<<n)  -  1].first + 1 << "\n";
  
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