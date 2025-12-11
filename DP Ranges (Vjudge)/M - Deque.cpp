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

std::mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
ll rand(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}
//--------------------------------------------------Global Memory-------------------------------------------------------
struct PermutationHashing {
    ll a, b, c, d, e;

    PermutationHashing(ll num1, ll num2, ll num3, ll num4, ll num5) {
        a = num1;
        b = num2;
        c = num3;
        d = num4;
        e = num5;
    }

    PermutationHashing() {
        a = rand(1, 1e9);
        b = rand(1, 1e9);
        c = rand(1, 1e9);
        d = rand(1, 1e9);
        e = rand(1, 1e9);
    }

    PermutationHashing operator+(PermutationHashing tmp) {
        return PermutationHashing(a+tmp.a, b+tmp.b, c+tmp.c, d+tmp.d, e+tmp.e);
    }

    PermutationHashing operator-(PermutationHashing tmp) {
        return PermutationHashing(a-tmp.a, b-tmp.b, c-tmp.c, d-tmp.d, e-tmp.e);
    }

    bool operator==(PermutationHashing tmp) {
        return a==tmp.a && b==tmp.b && c==tmp.c && d==tmp.d && e==tmp.e;
    }

};

int n;
vll arr;
ll dp[3001][3001];
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

ll spell (int l, int r) {
    if (l>r)
        return 0;
    if(l == r)
        return arr[l];

    if (~dp[l][r])
        return dp[l][r];

    ll takeLeft  = arr[l] - spell(l+1, r);
    ll takeRight = arr[r] - spell(l, r-1);

    return dp[l][r] = max(takeLeft, takeRight);
}

void magic() {
    cin >> n;

    arr.resize(n);
    readv(arr);

    memset(dp, -1, sizeof(dp));

    cout << spell(0, n-1);
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
