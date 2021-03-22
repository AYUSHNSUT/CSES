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
int n, m;
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

bool valid(int x , int y){
    return x>=0 && x<n && y>= 0 && y<m;
}

void solve(){

    cin >> n >> m;

    vector<vector <char>> a(n, vector<char>(m));
    vector <pii> monsterList;

    vvi travellerscore(n, vi(m,-1));
    vvi monsterscore(n, vi(m, -1));
    pii beginx;
    vector <pii> cornerlist;
    REP(i,n){
        REP(j,m){
            cin >> a[i][j];

            if(a[i][j] == 'M'){
                monsterList.pb({i,j});
                monsterscore[i][j] = 0;
            }

            if(a[i][j] == 'A'){
                beginx = mp(i,j);
                if(i == 0 || j == 0 || i==n-1 || j == m-1){
                    cornerlist.pb({i,j});
                }
            }

            if(a[i][j] == '.'){
                if(i == 0 || j == 0 || i==n-1 || j == m-1){
                    cornerlist.pb({i,j});
                }
            }
        }
    }


    queue <pair<pii, int>> q;
    q.push({beginx,0});
    travellerscore[beginx.first][beginx.second] = 0;
    for(auto monsta : monsterList){
    q.push({monsta,1});
    }
    int travels = 1;
    while(!q.empty() && travels){
        auto curr = q.front();
        int X =  curr.first.first;
        int Y = curr.first.second;
        int type = curr.second;
        q.pop();

        if(!type){
            travels--;
        }

        if(type == 0)
        {  for(int i = 0;i<4;i++){
                if(valid(X + dx[i], Y+ dy[i]) && travellerscore[X + dx[i]][Y+dy[i]] == -1 && a[X + dx[i]][Y+dy[i]] == '.' && (monsterscore[X + dx[i]][Y+dy[i]] == -1 || travellerscore[X + dx[i]][Y+dy[i]] < monsterscore[X + dx[i]][Y+dy[i]] )){
                    travellerscore[X + dx[i]][Y+dy[i]] = travellerscore[X][Y]+1;
                    q.push({mp(X + dx[i],Y+dy[i]),type});
                    travels++;
                 }
            }
        }
        else
        {
            for(int i = 0;i<4;i++){
            if(valid(X + dx[i], Y+ dy[i]) && (monsterscore[X + dx[i]][Y+dy[i]] == -1 || monsterscore[X + dx[i]][Y+dy[i]] > monsterscore[X][Y] + 1 )&& a[X + dx[i]][Y+dy[i]] == '.' && a[X + dx[i]][Y+dy[i]] != 'M'){
                monsterscore[X + dx[i]][Y+dy[i]] = monsterscore[X][Y]+1;
                q.push({mp(X + dx[i],Y+dy[i]), type});
            }
        }
            
        }
    }



    int ansf = false;
    DEBUG(cornerlist.size());
    for(auto corn : cornerlist){
        int xx = corn.first;
        int yy = corn.second;
        if((travellerscore[xx][yy]!= -1 && monsterscore[xx][yy] == -1) || (travellerscore[xx][yy]!= -1 && monsterscore[xx][yy] != -1 && travellerscore[xx][yy] < monsterscore[xx][yy])){
            cout << "YES\n";
            cout << travellerscore[xx][yy] << "\n";
            if(travellerscore[xx][yy] == 0){
                return;
            }

            vector <char> ansfinal;
            while(true){


                for(int i = 0;i<4;i++){
                    if(valid(xx + dx[i], yy+ dy[i]) && travellerscore[xx + dx[i]][yy + dy[i]] - travellerscore[xx][yy] == -1){
                        if(i == 0){
                            ansfinal.pb('U');
                        }
                        if(i == 1){
                            ansfinal.pb('R');
                        }
                        if(i == 2){
                            ansfinal.pb('D');
                        }
                        if(i == 3){
                           ansfinal.pb('L');
                        }

                        xx += dx[i];
                        yy+=dy[i];
                        break;
                    }   

                }

                if(travellerscore[xx][yy] == 0){

                    reverse(all(ansfinal));
                    for(auto charr : ansfinal){
                        cout << charr;
                    }
                    return;
                }


            }
        }
    }

    cout << "NO\n";


  

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