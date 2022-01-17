#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int one, two, three, up = 0;
    cin >> one >> two >> three;
    while (true) {
        int a;
        cin >> a;
        // Just input a zero at the end of the input to terminate the program
        if (a == 0)
            break;
        
        if (one+two+three < two + three + a)
            up++;
        one = two;
        two = three;
        three = a;
    }

    cout << up << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}