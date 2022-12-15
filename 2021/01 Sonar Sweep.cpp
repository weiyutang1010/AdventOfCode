/*
 * generated by github.com/calgagi/cp_gen
 * author: weiyutang
 * file: A.cpp
 * time: Fri Feb 19 14:35:40 2021
 */

#include <bits/stdc++.h>
using namespace std;

/* ===== BEGIN USER CODE ===== */

#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

const int MOD = 1e9 + 7;
const vector<ii> dir {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void part1() {
    int n;
    cin >> n;

    int ans = 0;
    int y = 0;
    while (cin >> y) {
        if (y > n) {
            ans++;
        }
        n = y;
    }
    cout << ans << endl;
}

void part2() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int ans = 0;
    int y = 0;
    while (cin >> y) {
        if (y + n2 + n3 > n1 + n2 + n3) {
            ans++;
        }
        n1 = n2;
        n2 = n3;
        n3 = y;
    }    
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;
    
    while (t--) {
        part1();
        //part2();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}