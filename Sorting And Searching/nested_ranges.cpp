
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
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
//#undef _GLIBCXX_DEBUG
// uncomment for multiset and us less_equal in line below
//#define indexed_set tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> 

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
// ⡏⠉⠉⠉⠉⠉⠉⠋⠉⠉⠉⠉⠉⠉⠋⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠙⠉⠉⠉⠹
// ⡇⢸⣿⡟⠛⢿⣷⠀⢸⣿⡟⠛⢿⣷⡄⢸⣿⡇⠀⢸⣿⡇⢸⣿⡇⠀⢸⣿⡇⠀
// ⡇⢸⣿⣧⣤⣾⠿⠀⢸⣿⣇⣀⣸⡿⠃⢸⣿⡇⠀⢸⣿⡇⢸⣿⣇⣀⣸⣿⡇⠀
// ⡇⢸⣿⡏⠉⢹⣿⡆⢸⣿⡟⠛⢻⣷⡄⢸⣿⡇⠀⢸⣿⡇⢸⣿⡏⠉⢹⣿⡇⠀
// ⡇⢸⣿⣧⣤⣼⡿⠃⢸⣿⡇⠀⢸⣿⡇⠸⣿⣧⣤⣼⡿⠁⢸⣿⡇⠀⢸⣿⡇⠀
// ⣇⣀⣀⣀⣀⣀⣀⣄⣀⣀⣀⣀⣀⣀⣀⣠⣀⡈⠉⣁⣀⣄⣀⣀⣀⣠⣀⣀⣀⣰
// ⣇⣿⠘⣿⣿⣿⡿⡿⣟⣟⢟⢟⢝⠵⡝⣿⡿⢂⣼⣿⣷⣌⠩⡫⡻⣝⠹⢿⣿⣷
// ⡆⣿⣆⠱⣝⡵⣝⢅⠙⣿⢕⢕⢕⢕⢝⣥⢒⠅⣿⣿⣿⡿⣳⣌⠪⡪⣡⢑⢝⣇
// ⡆⣿⣿⣦⠹⣳⣳⣕⢅⠈⢗⢕⢕⢕⢕⢕⢈⢆⠟⠋⠉⠁⠉⠉⠁⠈⠼⢐⢕⢽
// ⡗⢰⣶⣶⣦⣝⢝⢕⢕⠅⡆⢕⢕⢕⢕⢕⣴⠏⣠⡶⠛⡉⡉⡛⢶⣦⡀⠐⣕⢕
// ⡝⡄⢻⢟⣿⣿⣷⣕⣕⣅⣿⣔⣕⣵⣵⣿⣿⢠⣿⢠⣮⡈⣌⠨⠅⠹⣷⡀⢱⢕
// ⡝⡵⠟⠈⢀⣀⣀⡀⠉⢿⣿⣿⣿⣿⣿⣿⣿⣼⣿⢈⡋⠴⢿⡟⣡⡇⣿⡇⡀⢕
// ⡝⠁⣠⣾⠟⡉⡉⡉⠻⣦⣻⣿⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣦⣥⣿⡇⡿⣰⢗⢄
// ⠁⢰⣿⡏⣴⣌⠈⣌⠡⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣬⣉⣉⣁⣄⢖⢕⢕⢕
// ⡀⢻⣿⡇⢙⠁⠴⢿⡟⣡⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣵⣵⣿
// ⡻⣄⣻⣿⣌⠘⢿⣷⣥⣿⠇⣿⣿⣿⣿⣿⣿⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣷⢄⠻⣿⣟⠿⠦⠍⠉⣡⣾⣿⣿⣿⣿⣿⣿⢸⣿⣦⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟
// ⡕⡑⣑⣈⣻⢗⢟⢞⢝⣻⣿⣿⣿⣿⣿⣿⣿⠸⣿⠿⠃⣿⣿⣿⣿⣿⣿⡿⠁⣠
// ⡝⡵⡈⢟⢕⢕⢕⢕⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠿⠋⣀⣈⠙
// ⡝⡵⡕⡀⠑⠳⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢉⡠⡲⡫⡪⡪⡣
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////



class FT{
    ll n;
    vl tree;
    public:
        FT(ll n) : n(n){
            tree.resize(n+2);
        }

    void add(ll pos,ll x){
        while(pos <= n ){
            tree[pos]+=x;
            pos+= pos&(-pos);
        }

    }

    ll sum(ll point){
        ll res = 0;
       // DEBUG(point);

        //DEBUG(tree.size());
        if(!point) return 0;
        while(point >= 1){
            // DEBUG(res);
            // DEBUG(point);
        //    DEBUG(point);
            res += tree[point];
            point -= point & (-point);
            // DEBUG(point);
        }
        // cerr << "\n439\n";
        return res;
    }
};

bool customSort(const array<ll,4> &a, const array<ll,4> &b){
    return a[0] < b[0] ||(a[0] == b[0] &&  a[1] < b[1]) || (a[0] == b[0] && a[1] == b[1] &&a[2] > b[2]);
}

void solve(){
    ll n;
    cin >> n;

    vector <pll> a(n);
    vl pts;
    REP(i,n){
        cin >> a[i].first >> a[i].second;
        pts.pb(a[i].first);
        // DEBUG(pts.back());
        pts.pb(a[i].second);
        //   DEBUG(pts.back());
    }

    sort(all(pts));
    // for(auto p : pts){
    //     DEBUG(p);
    // }
    auto enditr = unique(all(pts));
    int totCord = std::distance(pts.begin(), enditr);
    //DEBUG(totCord);
    unordered_map <ll,ll> x;
    vector <array<ll,4>> b;
    for(int i = 0;i<totCord;i++){
        x[pts[i]] = i;
        // DEBUG(i);
        // DEBUG(pts[i]);
        // DEBUG(x[pts[i]]);
    }

    for(int i = 0;i<n;i++){
        ll p = x[a[i].first];
        // DEBUG(a[i].first);
        // DEBUG(p);
        ll q = x[a[i].second];
        // DEBUG(a[i].second);
        // DEBUG(q);
        array <ll,4> t = {p, 0,q,i};
        b.push_back(t);
        array <ll,4> s = {q, 1, p,i};
        b.push_back(s);
    }

    sort(all(b),customSort);
    FT startPts(totCord), endPts(totCord);
    vl contains(n);
    vl contained(n);
    for(auto i : b){
        // DEBUG(i[0]);
        // DEBUG(i[1]);
        // DEBUG(i[2]);
        // DEBUG(i[3]);
        if(i[1] == 0){
            //DEBUG(x.size());
            ll tot_started = endPts.sum(x.size());
            ll started_till_here =  endPts.sum(i[2]);
            // DEBUG(tot_started);
            // DEBUG(started_till_here);
            contained[i[3]] = tot_started - started_till_here;
            endPts.add(i[2]+1, 1);
        }
        else{
            ll started_till  = startPts.sum(i[0]+1);
            ll started_before =  startPts.sum(i[2]);
            // DEBUG(started_till);
            // DEBUG(started_before);
            contains[i[3]] = started_till - started_before;
            startPts.add(i[2]+1, +1);
        }
    }

    for(int i = 0;i<n;i++){
        ll k = contains[i] > 0 ? 1 : 0 ;
        cout << contains[i]<< " "; 
    }
    cout << endl;
    for(int i = 0;i<n;i++){
        ll j = contained[i] > 0 ? 1 : 0;
        cout << contained[i] << " ";
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
   //cin >> t; 
   while(t--){
       solve();
   }
}