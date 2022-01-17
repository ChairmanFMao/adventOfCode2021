#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* 1 76 38 96 62 41 27 33 4 2 94 15 89 25 66 14 30 0 71 21 48 44 87 73 60 50 77 45 29 18 5 99 65 16 93 95 37 3 52 32 46 80 98 63 92 24 35 55 12 81
 51 17 70 78 61 91 54 8 72 40 74 68 75 67 39 64 10 53 9 31 6 7 47 42 90 20 19 36 22 43 58 28 79 86 57 49 83 84 97 11 85 26 69 23 59 82 88 34 56 13 */
// Input with spaces instead of commas, remember to use instead of select all
// Set numbers to -1 when they have been chosen
// Had a silly bug where I used double equals when attempting to assign a variable

vector<vector<vector<int>>> boards;

int processScore(vector<vector<int>> board, int last) {
    int all = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] != -1)
                all += board[i][j];
        }
    }
    return all * last;
}

int winner(int last) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 5; j++) {
            bool good1 = 1, good2 = 1;
            for (int k = 0; k < 5; k++) {
                if (boards[i][j][k] != -1)
                    good1 = 0;
            }
            for (int k = 0; k < 5; k++) {
                if (boards[i][k][j] != -1)
                    good2 = 0;
            }
            if (good1 || good2)
                return processScore(boards[i], last);
        }
        bool good3 = 1, good4 = 1;
        for (int j = 0; j < 5; j++) {
            if (boards[i][j][j] != -1)
                good3 = 0;
        }
        for (int j = 0; j < 5; j++) {
            if (boards[i][j][4-j] != -1)
                good4 = 0;
        }
        if (good3 || good4)
            return processScore(boards[i], last);
    }
    return -1;
}

void remove(int number) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (boards[i][j][k] == number)
                    boards[i][j][k] = -1;
            }
        }
    }
}

void solve() {
    queue<int> numbers;
    for (int i = 0; i < 100; i++) {
        int a;
        cin >> a;
        numbers.push(a);
    }

    for (int i = 0; i < 100; i++) {
        vector<vector<int>> current;
        for (int j = 0; j < 5; j++) {
            vector<int> immediate;
            for (int k = 0; k < 5; k++) {
                int a;
                cin >> a;
                immediate.push_back(a);
            }
            current.push_back(immediate);
        }
        boards.push_back(current);
    }

    for (int i = 0; i < 100; i++) {
        int destroy = numbers.front();
        numbers.pop();
        remove(destroy);
        int a = winner(destroy);
        if (a != -1) {
            cout << a << "\n";
            return;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}