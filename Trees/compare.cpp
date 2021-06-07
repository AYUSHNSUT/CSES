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
    ifstream fin1("comp_out.txt");
    ifstream fin2("output.txt");
    ifstream fin3("input.txt");
    

    ll a , b;
    int i = 0;
    while(fin1>>a){
        i++;
        fin2>>b;

        // DEBUG(a);
        // DEBUG(b);

        if(a != b){
            cout << i << endl;
            ll n , x;
            fin3 >> n >> x;
                ll tmp1,tmp2;
            REP(j,n){
                fin3 >> tmp1;
            }
             REP(j,n-1){
                fin3 >> tmp1 >> tmp2;
            }

            REP(j,i){
                fin3 >>  tmp1 >> tmp2;
            }
            cout << tmp1 << " " << tmp2;


            break;
        }
    }

}



int main(){



    // #ifdef mishrable
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif



   fast_cin();
   int t =1;
   cin >> t; 
   while(t--){
       solve();
   }
}