#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Finally worked when I realised I was having an issue with storing the numbers as chars instead of ints
// I was previously setting the chars to zero when they went over 9, I shouldv'e been setting them to 48 as that is the ascii value for 0

ll flashes = 0;
int levels[10][10];

void oneStep() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            levels[i][j]++;
    }
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
    for (int i = 0; i < 100; i++) {
        oneStep();
        checkFlashes();
    }
    cout << flashes << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}