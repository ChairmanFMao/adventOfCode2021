#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Worked after a little big of debugging the smallest function

vector<string> numbers;
bool used[100][100];

bool smallest(int i, int j) {
    if (i == 0 && j == 0)
        return numbers[i][j] < numbers[i][j+1] && numbers[i][j] < numbers[i+1][j];
    else if (i == 99 && j == 99)
        return numbers[i][j] < numbers[i][j-1] && numbers[i][j] < numbers[i-1][j];
    else if (i == 99 && j == 0)
        return numbers[i][j] < numbers[i-1][j] && numbers[i][j] < numbers[i][j+1];
    else if (i == 0 && j == 99)
        return numbers[i][j] < numbers[i+1][j] && numbers[i][j] < numbers[i][j-1];
    else if (i == 0)
        return numbers[i][j] < numbers[i+1][j] && numbers[i][j] < numbers[i][j+1] && numbers[i][j] < numbers[i][j-1];
    else if (j == 0)
        return numbers[i][j] < numbers[i][j+1] && numbers[i][j] < numbers[i+1][j] && numbers[i][j] < numbers[i-1][j];
    else if (i == 99)
        return numbers[i][j] < numbers[i][j+1] && numbers[i][j] < numbers[i][j-1] && numbers[i][j] < numbers[i-1][j];
    else if (j == 99)
        return numbers[i][j] < numbers[i][j-1] && numbers[i][j] < numbers[i-1][j] && numbers[i][j] < numbers[i+1][j];
    else
        return numbers[i][j] < numbers[i+1][j] && numbers[i][j] < numbers[i-1][j] && numbers[i][j] < numbers[i][j+1] && numbers[i][j] < numbers[i][j-1];
}

// This wasn't working properly until I added the 2D array called used to make sure that numbers weren't being used multiple times
ll basinSize(int i, int j) {
    ll basin = 0;
    queue<pair<int,int>> points;
    points.push({i,j});
    while (!points.empty()) {
        int x = points.front().first, y = points.front().second;
        points.pop();
        if (used[x][y])
            continue;
        basin++;
        if (x != 99) {
            if (numbers[x+1][y] > numbers[x][y] && numbers[x+1][y] != '9')
                points.push({x+1,y});
        }
        if (y != 99) {
            if (numbers[x][y+1] > numbers[x][y] && numbers[x][y+1] != '9')
                points.push({x,y+1});
        }
        if (x != 0) {
            if (numbers[x-1][y] > numbers[x][y] && numbers[x-1][y] != '9')
                points.push({x-1,y});
        }
        if (y != 0) {
            if (numbers[x][y-1] > numbers[x][y] && numbers[x][y-1] != '9')
                points.push({x,y-1});
        }
        used[x][y] = 1;
    }
    return basin;
}

void solve() {
    for (int i = 0; i < 100; i++) {
        string s;
        cin >> s;
        numbers.push_back(s);
    }

    memset(used, 0, sizeof used);

    ll first = 0, second = 0, third = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (smallest(i, j)) {
                ll based = basinSize(i,j);
                if (based >= first) {
                    third = second;
                    second = first;
                    first = based;
                } else if (based >= second) {
                    third = second;
                    second = based;
                } else if (based > third)
                    third = based;
            }
        }
    }
    cout << first*second*third << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}