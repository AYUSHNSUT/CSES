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
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////
void solve()
{
    int n;
    cin >> n;
    std::vector<pii> B(n);

    vector <   pair <pii, int>  > A(n);

    REP(i,n){
      cin >> A[i].first.first >> A[i].first.second;
      B[i].first = A[i].first.first;
      B[i].second = A[i].first.second;
      A[i].second = i;
    }

    sort(all(A));
    // sort(all(A));

    priority_queue <pii , vector <pii> , greater <pii>> pq;
    int room = 1;
    vi roomz(n);

    for(int i = 0;i<n;i++){
      pii curr = A[i].first;
      // DEBUG(i);
      // DEBUG(pq.empty());
      // DEBUG(curr.first);
      // DEBUG(curr.second);
      // cout << "\n****************\n status of pq\n";

      // priority_queue <pii, vector <pii>, greater<pii>> pqt = pq;
      //
      // while(!pqt.empty())
      // {
      //   auto tmpp = pqt.top();
      //   DEBUG(pqt.top().second);
      //   pqt.pop();
      // }

      // DEBUG(A[i].second);
      // if(!pq.empty())
      // {
      //     int firstfree = pq.top().first;
      //     DEBUG(firstfree);
      //     DEBUG(pq.top().second);
      // }
      if(pq.empty() || pq.top().first>= curr.first)
      {
        pq.push(mp(curr.second, room));
        // cout << "Inserting room";
        // DEBUG(room);
        roomz[A[i].second] = room++;
        // cout << "New room\n";
        // DEBUG(room-1);
        // DEBUG(roomz[A[i].second]);
      }

      else{
        pii extractedRoom = pq.top();
        // DEBUG(extractedRoom.second);
        pq.pop();
        roomz[A[i].second] = extractedRoom.second;
        pq.push(mp(curr.second, roomz[A[i].second]));
        // DEBUG(roomz[A[i].second]);
      }

    }

    cout << room-1 << "\n";;
    REP(i,n)
    {
      cout << roomz[i] <<  " ";
    }
}

int main()
{

    std::ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;

    while(t--)
      {
        solve();
      }




//fout.close();
//fin.close();
    return 0;
}
