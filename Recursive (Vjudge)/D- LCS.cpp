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
string s, t;
int const N = 3001;
int dp[N][N];
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
    if (i == s.size() || j == t.size()) return 0;

    if (~dp[i][j])
        return dp[i][j];

    if (s[i] == t[j]) {
        return dp[i][j] = spell(i + 1, j + 1) + 1;
    }

    int ch1 = spell(i + 1, j);
    int ch2 = spell(i, j + 1);

    return dp[i][j] = max(ch1, ch2);
}

string build(int i, int j) {
    if (i == s.size() || j == t.size()) return "";

    if (s[i] == t[j])
        return s[i] + build(i + 1, j + 1);


    if (dp[i + 1][j] >= dp[i][j + 1])
        return build(i + 1, j);
    else
        return build(i, j + 1);
}

void magic() {
    cin >> s >> t;

    memset(dp, -1, sizeof(dp));

    spell(0,0);

    cout << build(0,0);
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
