#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, up = 0;
    cin >> a;
    // To terminate the input just add a zero on the end of the data
    while (a) {
        int b;
        cin >> b;
        if (b > a)
            up++;
        a = b;
    }
    cout << up << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}