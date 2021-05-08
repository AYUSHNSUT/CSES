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
vl maxHeight, maxAns;
vl parentArray;
vl dp1,dp2;
vl secHeight;
vl finalAns;

vvl G;
ll dfs(ll source, ll parent, vvl &G, vl &vis){
  //  DEBUG(source);

    vis[source] = 1;
    parentArray[source] = parent;

    if(maxHeight[source] != -1){
        return maxHeight[source];
    }
    vector <int> unvis;
    for(auto c : G[source]){
        if(!vis[c]){
            unvis.pb(c);
        }
    }
    if(unvis.size() == 0){
        maxHeight[source] = 0;
        return maxHeight[source];
    }

    if(unvis.size() == 1){
        maxHeight[source] = 1 + dfs(unvis[0], source, G , vis);
        return maxHeight[source];
    }
    ll maxTemp = -1;

        for(auto child : unvis){
        // DEBUG(child);
            if(!vis[child] && child != parent)
            {
                maxTemp = max(maxTemp, 1 + dfs(child,source,G,vis));
            }
        }

    maxHeight[source] = maxTemp;
    return maxHeight[source];
}

void in_out_dp(ll source, ll parent, ll passedAnswer){
    vl suffixAns,prefixAns;

    // DEBUG(source);
    // DEBUG(parent);
    // DEBUG(passedAnswer);

    for(auto child : G[source]){
        if(child!=parent){
            // DEBUG(child);
            // DEBUG(maxHeight[child]);
            suffixAns.pb(maxHeight[child]);
            prefixAns.pb(maxHeight[child]);
        }
    }

    for(int i = 1;i<prefixAns.size();i++){
        prefixAns[i] = max(prefixAns[i-1], prefixAns[i]);
    }

    for(int i = suffixAns.size()-2;i>=0;i--){
        suffixAns[i] = max(suffixAns[i+1], suffixAns[i]);
    }

    int child_no = 0;

    for(auto k : G[source]){
        if(k!= parent){
            ll ans1 = (child_no == 0) ? INT_MIN :prefixAns[child_no-1];
            ll ans2 = (child_no == suffixAns.size()-1) ? INT_MIN : suffixAns[child_no+1];
            ll ans = max(ans1,ans2);

            ll partial_ans = 1 + max(passedAnswer , ans);

            in_out_dp(k,source,partial_ans);
            child_no++;
        }
    }

    finalAns[source] = 1 + max(passedAnswer , suffixAns.size() == 0 ? -1 : suffixAns[0]);
}

void solve(){
    ll n;
    cin >> n;

    G.resize(n+1);

    maxHeight.resize(n+1,-1);
    secHeight.resize(n+1,-1);
    maxAns.resize(n+1 , -1);
    parentArray.resize(n+1 , -1);
    finalAns.resize(n+1,-1);

    vl vis(n+1);
    REP(i,n-1){
        ll a , b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(1,1,G,vis);

    vis.clear();
    vis.resize(n+1);


    in_out_dp(1,0,-1);

    for(int i = 1;i<=n;i++){
        cout << finalAns[i] << " ";
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
  // cin >> t; 
   while(t--){
       solve();
   }
}