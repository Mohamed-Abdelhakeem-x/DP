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
string s;
int lt, rt;
int const N = 5001;
int dpSpell[N][N];
int dpPal[N][N];
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

int isPal(int l, int r) {
    if (l >= r) return 1;
    if (s[l] != s[r]) return 0;

    if (~dpPal[l][r])
        return dpPal[l][r];

    return dpPal[l][r] = isPal(l + 1, r - 1);
}

int spell(int l, int r){
    if (l > r ) return 0;
    if (l == r) return 1;

    if (~dpSpell[l][r])
        return dpSpell[l][r];

    return dpSpell[l][r] = spell(l+1, r) + spell(l, r-1) - spell(l+1, r-1) + isPal(l, r);
}

void magic() {
    cin >> lt >> rt;
    lt--; rt--;

    cout << spell(lt, rt) << endl;
}
//------------------------------------------------------Main------------------------------------------------------------
signed main() {
    fast();

    cin >> s;

    int t=1;
    cin >> t;

    memset(dpSpell, -1, sizeof(dpSpell));
    memset(dpPal, -1, sizeof(dpPal));

    while (t--) {
        magic();
    }

    return 0;
}
