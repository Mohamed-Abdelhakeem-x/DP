/*
Author: WolfHakeem
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define u128 unsigned __int128
#define ull unsigned long long
#define ld long double

// Containers
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define pll pair<ll,ll>

// IO helpers
#define readv(v) for(auto& i : v) cin >> i
#define printv(v) for(auto& i : v) cout << i << " "
#define all(x) (x).begin(), (x).end()
#define in(i,n) (0 <= (i) && (i) < (n))
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define INF 2e18

// 128-bit IO
#define read128(x) { string s; cin >> s; __int128 val = 0; bool neg = false; \
if (s[0]=='-'){ neg = true; s = s.substr(1);} \
for(char c:s) val = val*10 + (c-'0'); x = neg? -val : val; }

#define print128(x) { __int128 val=x; if(val==0) cout<<"0"; \
else{ if(val<0){ cout<<"-"; val=-val;} string s; \
while(val){ s += '0'+(val%10); val/=10;} reverse(all(s)); cout<<s; } }

// Min/Max update helpers: assign a = b if it improves (smaller for chmin, larger for chmax)
template<typename T> inline bool chmin(T& a, const T& b){ if(b < a){ a=b; return true;} return false; }
template<typename T> inline bool chmax(T& a, const T& b){ if(b > a){ a=b; return true;} return false; }

// Debug printing (only active when not running on Codeforces)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << "\n"
#else
#define debug(x)
#endif

// 4-direction movement for grid problems (up, down, left, right)
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

// 8-direction knight moves for chess/graph problems
int kx[8]={1,1,2,2,-1,-1,-2,-2};
int ky[8]={2,-2,1,-1,2,-2,1,-1};

// gcd wrapper and lcm function using built-in gcd
#define gcd __gcd
ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
//--------------------------------------------------Global Memory-------------------------------------------------------
string a, b, c;
int dp[1001][1001];
//----------------------------------------------------Functions---------------------------------------------------------
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void set_file(string &file_name) {
    freopen((file_name + ".in").c_str(), "r", stdin);
    freopen((file_name + ".out").c_str(), "w", stdout);
}

int spell(int i, int j) {
    int k = i + j;

    if (i == a.size()) {
        int cost = 0;
        for (int x = j; x < b.size(); x++) cost += (b[x] != c[k++]);
        return cost;
    }

    if (j == b.size()) {
        int cost = 0;
        for (int x = i; x < a.size(); x++) cost += (a[x] != c[k++]);
        return cost;
    }

    if (~dp[i][j])
        return dp[i][j];

    int cost1 = spell(i+1, j) + (a[i] != c[k]);
    int cost2 = spell(i, j+1) + (b[j] != c[k]);

    return dp[i][j] = min(cost1, cost2);
}

void magic() {
    cin >> a >> b >> c;
    memset(dp, -1, sizeof(dp));
    cout << spell(0,0) << endl;
}
//------------------------------------------------------Main------------------------------------------------------------
signed main() {
    fast();

    int t = 1;
    cin >> t;

    while (t--) {
        magic();
    }

    return 0;
}
