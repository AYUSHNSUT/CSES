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

/* TODO :
1. Sort the points in ascending order of ending timespes.
2. DP :
A. For each element , we can either select it or not
a. If selected , DP[i] = Dp[last ended elemet] + current const
b. If not , Dp[i] = Dp[i-1];
B. Since elements are sorted, we can get last ended element using binary search
*/

ll binsearch(vi &arr, ll x, ll low , ll high){
 
    // DEBUG(low);
    // DEBUG(high);
    ll mid = (low + high) / 2;
    // DEBUG(mid);
    // DEBUG(arr[mid]);
    // DEBUG(x);

    if(arr[low] >= x){
        return -1;
    }
    if(arr[high] < x){
        return high;
    }


    if(low > high){
        return -1;
    }
    if(arr[mid] < x){
    //    cerr << "YE WL\n";
        ll retValue = binsearch(arr, x, mid+1 , high);
        return  retValue == -1 ? mid : retValue ;
    }
    //cerr << "AAA\n";
    ll retValue = binsearch(arr, x , low, mid-1);
   // DEBUG(retValue);
   // return retValue == -1 ? mid : retValue;
   return retValue;
}

void solve(){
    ll n;
    cin >> n;

    vvi a(n, vi (3));
    REP(i,n){
        ll t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        a[i][0] = t2;
        a[i][1] = t1;
        a[i][2] = t3;
    }
    sort(all(a));
;
    // for(auto elem : a){
    //     cerr << elem[1] << " " << elem[0] << " " << elem[2] << endl;
    // }
    vl dp(n);

    vi starts(n), ends(n), vals(n);

    REP(i,n){
        starts[i] = a[i][1];
        ends[i] = a[i][0];
        vals[i] = a[i][2];
    }

    dp[0] = vals[0];
    for(ll i = 1;i<n;i++){
        ll st= starts[i];
        ll en = ends[i];
        ll val = vals[i];
        ll findPos = binsearch(ends, st, 0, i-1);
      //  DEBUG(ends[findPos]);
        if(findPos < 0 || ends[findPos] >= st){
            findPos--;
        }
       // cerr << "I = " << i << "  findPos = " << findPos << endl;
    
        if(findPos <= -1){
            dp[i] = max(dp[i-1], (long long)val);
        }

        else{
            dp[i] = max(dp[findPos] + (long)val , dp[i-1]);
        }

       // DEBUG(dp[i]);
    }

    cout << dp[n-1] << endl;


}



int main(){



    #ifdef mishrable
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif



   fast_cin();
   ll t =1;
   //cin >> t; 
   while(t--){
       solve();
   }
}