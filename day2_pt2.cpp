#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll x = 0, y = 0, aim = 0;
    string direction;
    ll magnitude;
    cin >> direction >> magnitude;
    // To terminate the program just put in a random string and 0
    while (magnitude) {
        if (direction == "up")
            aim-=magnitude;
        else if (direction == "down")
            aim+=magnitude;
        else if (direction == "forward") {
            x+=magnitude;
            y+=aim*magnitude;
        }
        cin >> direction >> magnitude;
    }
    cout << x * y << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}