#include<bits/stdc++.h>
using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(long long i=0;i<(n);i++)
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
ll n, m;
ll transform(ll x , ll y){
    return x*n + y;
}

pll revert(ll x){
    return {x/n, x%n};
}

void solve(){
    
    cin >> n >> m;

    vvl a(n, vl(m));
    vector <pair <ll,ll>> sortarray;
    REP(i,n){
        REP(j,m){
            cin >> a[i][j];
            sortarray.pb({a[i][j], transform(i,j)});
        }
    }

    sort(all(sortarray));

    vvl assigned(n, vl(m,-1));
    vvl done(m, vl(n));

    vvl ansvectr(m, vl(n));

    for(ll i = 0;i<m;i++){
        pll path = sortarray[i];
        pll coord = revert(path.second);

        assigned[coord.first][coord.second] = i;
        done[i][coord.first] = 1;
        // ansvectr[i][coord.first] = a[coord.first][coord.second];
    }

    for(ll runner = 0;runner<m;runner++){
        for(ll path = 0;path<n;path++){
            if(done[runner][path]){
                continue;
            }

            for(ll i = 0;i<m;i++){
                if(assigned[path][i] == -1){
                    assigned[path][i] = runner;
                    done[runner][path] = 1;
                    break;
                }
            }
        }
    }

    REP(i,n){
        REP(j,m){
            ll runner = assigned[i][j];
            // cerr << runner<< " ";
            ansvectr[runner][i] = a[i][j];
        }
        // cerr << endl;
    }

    REP(i,n){
        REP(j,m){
            cout << ansvectr[j][i] << " ";
        }
        cout << "\n";
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
   cin >> t; 
   while(t--){
       solve();
   }
}