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
int dx4[4] = {1,-1,0,0};
int dy4[4] = {0,0,1,-1};
 
// 8-direction knight moves for chess/graph problems
int kx[8]={1,1,2,2,-1,-1,-2,-2};
int ky[8]={2,-2,1,-1,2,-2,1,-1};
 
// gcd wrapper and lcm function using built-in gcd
#define gcd __gcd
ll lcm(ll a, ll b){ return a / gcd(a, b) * b; }
//--------------------------------------------------Global Memory-------------------------------------------------------
int n;
const int N = 400000 + 5;
vector<pair<int,int>> Day[N];
ll dp[N];
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
 
ll spell(ll day) {
    if (day >= n)
        return 0;
 
    ll &res = dp[day];
    if (res != -1) return res;
 
    res = spell(day + 1); // skip this day
 
    for (auto [R, W] : Day[day]) {
        res = max(res, spell(R + 1) + W);
    }
 
    return res;
}
 
void magic() {
    cin >> n;
 
    vector<int> L(n), R(n), W(n);
 
    map<int,int> mp;
 
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i] >> W[i];
        mp[L[i]];
        mp[R[i]];
    }
 
    int id = 0;
    for (auto &x : mp) x.second = id++;
 
    for (int i = 0; i < n; i++) {
        L[i] = mp[L[i]];
        R[i] = mp[R[i]];
    }
 
    for (int i = 0; i <= id; i++) Day[i].clear();
 
    for (int i = 0; i < n; i++) {
        Day[L[i]].push_back({R[i], W[i]});
    }
 
    memset(dp, -1, sizeof(dp));
 
    n = id;
 
    cout << spell(0) << "\n";
}
//------------------------------------------------------Main------------------------------------------------------------
signed main() {
    fast();
 
    int t=1;
    //cin >> t;
 
    while (t--) {
        magic();
    }
 
    return 0;
}
