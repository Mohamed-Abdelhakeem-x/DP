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
int k, m;
vpii bags;
int const M = 51, K = 1001;
int dp[M][K];
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

int spell(int i, int curr) {
    if (i == m) return 0;

    if (~dp[i][curr])
        return dp[i][curr];

    int ch1 = spell(i+1, curr);
    int ch2=0;
    if (curr - bags[i].first >= 0)
        ch2 = spell(i+1, curr-bags[i].first) + bags[i].second;

    return dp[i][curr] = max(ch1, ch2);
}

void magic() {
    cin >> k >> m;

    bags.resize(m);
    for (int i=0; i<m; i++) cin >> bags[i].first >> bags[i].second;

    memset(dp, -1, sizeof(dp));

    cout << "Hey stupid robber, you can get " << spell(0, k) << ".\n";
}
//------------------------------------------------------Main------------------------------------------------------------
signed main() {
    fast();

    int t;
    cin >> t;

    while (t--) {
        magic();
    }

    return 0;
}
