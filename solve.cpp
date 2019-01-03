#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;
//using namespace __gnu_pbds;

#define llong long long
#define dlong double long
#define ulong unsigned long long
#define endl '\n'
#define pb push_back
#define F first
#define S second

// CODE CODE CODE CODE CODE CODE CODE CODE CODE

const llong N = 10;
const llong M = 1e3 + 36;
const llong INF = 2e9+7;
const llong MOD = 987654323;
const llong MOD1 = 1e9 + 7;
const llong MOD2 = 1e9 + 9;
const llong MOD3 = 1e18 + 3;
const int XK[4] = {-1, 0, 1, 0};
const int YK[4] = {0, -1, 0, 1};
const int X[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int Y[8] = {2, -2, 2, -2, 1, -1, 1, -1};

//tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());




signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("gathering.in", "r", stdin);
//    freopen("gathering.out", "w", stdout);
#endif // LOCAL
    string H;

    FILE *fp;

    if((fp = fopen("input.txt", "r")) == NULL) {
        printf ("Cannot open file.\n");
        exit(1);
    }
    char buf[4096];
    for (size_t read_c; read_c = fread(buf, 1, 4, fp); ) {
        std::string s(buf, buf + read_c);
        H += s;
    }
    fclose(fp);

    int n = int(H.size());
    vector < int > pi(n);
    pi[0] = 0;
    for (int i(1); i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && H[i] != H[j])
            j = pi[j - 1];
        if (H[i] == H[j]) {
            ++j;
        }
        pi[i] = j;
    }

    if((fp = fopen("out.txt", "r")) == nullptr) {
        printf ("Cannot open file.\n");
        exit(1);
    }
    int now = 0;
    llong pos = 0;
    for (size_t read_c; read_c = fread(buf, 1, 4, fp); ) {
        string s(buf, buf + read_c);
        for (auto to:s) {
            pos++;
            while (now > 0 && to != H[now])
                now = pi[now - 1];
            if (to == H[now]) {
                ++now;
            }
            if (now == n - 1) {
                cout << pos - n + 1 << endl;
            }
        }
    }
    fclose(fp);
    return 0;
}

