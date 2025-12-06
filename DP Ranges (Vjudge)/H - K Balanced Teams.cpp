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
#define neg_INF (-2e18)
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
int n, k;
int dp[5100][5100];
vi v;
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

int spell(int l, int r) {
    if (r == 0) return 0;
    if (l == v.size()) return 0;

    if (~dp[l][r])
        return dp[l][r];

    int ch1 = spell(l + 1, r);

    int j = l;
    while (j < v.size() && v[j] - 5 <= v[l]) j++;

    int ch2 = spell(j, r - 1) + (j - l);

    return dp[l][r] = max(ch1, ch2);
}

void magic() {
    cin >> n >> k;

    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));

    cout << spell(0, k);
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
