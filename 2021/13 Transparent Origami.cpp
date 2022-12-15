/*
 * generated by github.com/calgagi/cp_gen
 * author: weiyutang
 * file: AdventOfCode.cpp
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
const vector<ii> dir8 {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

string parse(string& st, string delimiter) {
    int pos = st.find(delimiter);
    if (pos == -1) {
        string temp = st;
        st = "";
        return temp;
    } else {
        string temp = st.substr(0, pos);
        st = st.substr(pos + delimiter.size());
        return temp;
    }
}

void part1(const vector<ii>& pts, const vector<pair<char,int>>& fold) {
    cout << "Part 1: " << endl;

    int n = 2000, m = 2000;
    vector<vector<int>> board(n, vector<int> (m));
    for (auto& [x, y]: pts) {
        board[y][x] = 1;
    }

    int ans = 0;
    int val = fold[0].s;
    for (int i = 0; i < n; i++) {
        for (int pt1 = val - 1, pt2 = val + 1; pt1 >= 0 && pt2 < m; pt1--, pt2++) {
            ans += board[i][pt1] || board[i][pt2];
        }
    }

    cout << ans << endl;
}

void part2(const vector<ii>& pts, const vector<pair<char,int>>& fold) {
    cout << "Part 2: " << endl;

    // Populate board with points
    int n = 2000, m = 2000;
    vector<vector<int>> board(n, vector<int> (m));
    for (auto& [x, y]: pts) {
        board[y][x] = 1;
    }

    for (auto& [axis, val]: fold) {
        if (axis == 'x') {
            for (int i = 0; i < n; i++) {
                int pt1, pt2;
                for (pt1 = val - 1, pt2 = val + 1; pt1 >= 0 && pt2 < m; pt1--, pt2++) {
                    board[i][pt1] = board[i][pt1] || board[i][pt2];
                }
            }
            m = val;
        } else {
            for (int i = 0; i < m; i++) {
                int pt1, pt2;
                for (pt1 = val - 1, pt2 = val + 1; pt1 >= 0 && pt2 < n; pt1--, pt2++) {
                    board[pt1][i] = board[pt1][i] || board[pt2][i];
                }
            }
            n = val;
        }
    }

    // Display board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (board[i][j] ? '@' : 'o') << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;

    // Read input
    string st;
    vector<ii> pts;
    while (getline(cin, st)) {
        if (st.size() < 1) {
            break;
        }
        int x = stoi(parse(st, ","));
        int y = stoi(st);
        pts.push_back({x,y});
    }

    vector<pair<char, int>> fold;
    while (getline(cin, st)) {
        parse(st, "fold along ");
        char axis = parse(st, "=")[0];
        int val = stoi(parse(st, " "));
        fold.push_back({axis, val});
    }

    // Start Solving
    while (t--) {
        part1(pts, fold);
        cout << endl;
        part2(pts, fold);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}