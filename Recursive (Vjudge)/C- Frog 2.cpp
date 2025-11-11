/*
Author: WolfHakeem
*/

#include <bits/stdc++.h>
//#include "cp-algo/number_theory/modint.hpp"
//#include "cp-algo/math/combinatorics.hpp"
using namespace std;
#define ll long long
#define u128 unsigned __int128
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vvc vector<vector<char>>
#define vvb vector<vector<bool>>
#define vd vector<double>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define readv(v) for(auto& i : v) cin >> i
#define printv(v) for(auto& i : v) cout << i << " "
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define read128(x) { \
string s; cin >> s; \
__int128 val = 0; bool neg = false; \
if (s[0] == '-') { neg = true; s = s.substr(1); } \
for (char c : s) val = val * 10 + (c - '0'); \
(x) = neg ? -val : val; \
}
#define print128(x) { \
__int128 val = (x); \
if (val == 0) { cout << "0"; } \
else { \
if (val < 0) { cout << "-"; val = -val; } \
string s; \
while (val > 0) { s += '0' + (val % 10); val /= 10; } \
reverse(s.begin(), s.end()); \
cout << s; \
} \
}
//--------------------------------------------------Global Memory-------------------------------------------------------
int n, k;
vi h;
const int N = 1e5+1;
int dp[N];
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

ll spell(int i) {
    if (i == 0) return 0;

    if (~dp[i])
        return dp[i];

    ll res = LLONG_MAX;

    for (int j = 1; j <= k; j++) {
        if (i - j >= 0) res = min(res, spell(i - j) + abs(h[i] - h[i - j]));
    }

    return dp[i] = res;
}

void magic() {
    cin >> n >> k;

    h.resize(n);
    readv(h);

    memset(dp, -1, sizeof(dp));

    cout << spell(n-1);
}
//------------------------------------------------------Main------------------------------------------------------------
signed main() {
    fast();

    int t;
    t = 1;

    while (t--) {
        magic();
    }

    return 0;
}
