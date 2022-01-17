#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int counter = 0;
    for (int i = 0; i < 200; i++) {
        string discard;
        for (int j = 0; j < 11; j++)
            cin >> discard;

        for (int j = 0; j < 4; j++) {
            string a;
            cin >> a;
            if (a.size() == 2 || a.size() == 3 || a.size() == 4 || a.size() == 7)
                counter++;
        }
    }
    cout << counter << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}