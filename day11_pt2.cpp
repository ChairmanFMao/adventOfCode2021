#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Finally worked when I realised I was having an issue with storing the numbers as chars instead of ints

ll flashes = 0;
int levels[10][10];

void oneStep() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            levels[i][j]++;
    }
}

bool allZero() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (levels[i][j] > 0)
                return false;
    return true;
}

void checkFlashes() {
    queue<pair<int,int>> toZero, toIncrement;
    bool working = 1;
    while (working) {
        working = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (levels[i][j] > 9) {
                    working = 1;
                    levels[i][j] = 0;
                    flashes++;
                    toZero.push({i,j});
                    toIncrement.push({i+1,j+1});
                    toIncrement.push({i+1,j});
                    toIncrement.push({i+1,j-1});
                    toIncrement.push({i,j+1});
                    toIncrement.push({i,j-1});
                    toIncrement.push({i-1,j+1});
                    toIncrement.push({i-1,j});
                    toIncrement.push({i-1,j-1});
                }
        while (!toIncrement.empty()) {
            pair<int,int> current = toIncrement.front();
            toIncrement.pop();
            if (current.first < 0 || current.second < 0 || current.first > 9 || current.second > 9)
                continue;
            levels[current.first][current.second]++;
        }
    }
    while (!toZero.empty()) {
        levels[toZero.front().first][toZero.front().second] = 0;
        toZero.pop();
    }
}

void solve() {
    for (int i = 0; i < 10; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < 10; j++)
            levels[i][j] = a[j] - 48;
    }
    // I set i to 1000 because I thought it would be a reasonable upper bound
    for (int i = 0; i < 1000; i++) {
        oneStep();
        checkFlashes();
        if (allZero()) {
            // Remember zero indexing *facepalm*
            cout << i+1 << "\n";
            return;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}