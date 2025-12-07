/*
Author: WolfHakeem
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define u128 unsigned __int128
#define ull unsigned long long
#define ld long double

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

#define readv(v) for(auto& i : v) cin >> i
#define printv(v) for(auto& i : v) cout << i << " "
#define all(x) (x).begin(), (x).end()
#define in(i,n) (0 <= (i) && (i) < (n))
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define INF 2e18
#define negINF (-2e18)
#define MOD 1000000007

#define read128(x) { string s; cin >> s; __int128 val = 0; bool neg = false; \
if (s[0]=='-'){ neg = true; s = s.substr(1);} \
for(char c:s) val = val*10 + (c-'0'); x = neg? -val : val; }

#define print128(x) { __int128 val=x; if(val==0) cout<<"0"; \
else{ if(val<0){ cout<<"-"; val=-val;} string s; \
while(val){ s += '0'+(val%10); val/=10;} reverse(all(s)); cout<<s; } }

template<typename T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T& a, const T& b) { if (b > a) { a = b; return true; } return false; }

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << "\n"
#else
#define debug(x)
#endif

int dx4[4] = { 1,-1,0,0 };
int dy4[4] = { 0,0,1,-1 };

int kx[8] = { 1,1,2,2,-1,-1,-2,-2 };
int ky[8] = { 2,-2,1,-1,2,-2,1,-1 };

#define gcd __gcd
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
//--------------------------------------------------Global Memory-------------------------------------------------------
int n, m, k;
vll p;
ll dp[5001][5001];
ll pref[5005];
//----------------------------------------------------Functions---------------------------------------------------------
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void set_file(string& file_name) {
    freopen((file_name + ".in").c_str(), "r", stdin);
    freopen((file_name + ".out").c_str(), "w", stdout);
}

ll spell(int l, int r) {
    if (r == k) return 0;
    if (l >= n) return negINF;

    if (~dp[l][r])
        return dp[l][r];

    ll ch1 = spell(l + 1, r);

    ll ch2 = negINF;
    if (l + m - 1 < n)
        ch2 = spell(l + m, r + 1) + pref[l + m - 1] - (l ? pref[l - 1] : 0);


    return dp[l][r] = max(ch1, ch2);
}

void magic() {
    cin >> n >> m >> k;

    p.resize(n);
    readv(p);

    for (int i = 0; i < n; i++)
        pref[i] = p[i] + (i ? pref[i - 1] : 0);

    memset(dp, -1, sizeof(dp));

    cout << spell(0,0);
}
//------------------------------------------------------Main------------------------------------------------------------
signed main() {
    fast();

    int t=1;
    // cin >> t;

    while (t--) {
        magic();
    }

    return 0;
}
