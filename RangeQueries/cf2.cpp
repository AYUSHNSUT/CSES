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
        ll n;
        cin >> n;
        string s;
        cin >> s;
     
        ll check=0;
     
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'M'){
                check++;
            }
        }
     
        if(check != s.size()/3){
            cout << "NO\n";
            return;
        }
        deque <ll> zero;
        vl one;
        ll i= 0;
        unordered_map<ll,ll> done;
        for(auto c: s){
            if(c== 'T'){
                zero.pb(i);
            }
            else{
                one.pb(i);
            }
            i++;
        }
     
     
        for(auto o : one){
     
            if(zero.empty()){
               cout << "NO\n";
               return;
            }
            ll fron = zero.front();
            zero.pop_front();
            if(o < fron){
                cout << "NO\n";
                return;
            }
            done[fron] = o;
        }
        vl left_zero;
        for(auto z: zero){
            if(!done[z]){
                left_zero.pb(z);
            }
        }

        for(int i = one.size()-1;i>=0;i--){
            if(left_zero.empty()){
                 cout << "NO\n";
                return;
            }
            ll test = left_zero.back();
            left_zero.pop_back();
            if(one[i] > test){
                cout << "NO\n";
                return;
            }
        }

        cout << "YES\n";
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
       cin >> t; 
       while(t--){
           solve();
       }
    }

