#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* 3 1 5 4 4 4 5 3 4 4 1 4 2 3 1 3 3 2 3 2 5 1 1 4 4 3 2 4 2 4 1 5 3 3 2 2 2 5 5 1 3 4 5 1 5 5 1 1 1 4 3 2 3 3 3 4 4 4 5 5 1 3 3 5 4 5 5 5 1 1 2 4 
3 4 5 4 5 2 2 3 5 2 1 2 4 3 5 1 3 1 4 4 1 3 2 3 2 4 5 2 4 1 4 3 1 3 1 5 1 3 5 4 3 1 5 3 3 5 4 2 3 4 1 2 1 1 4 4 4 3 1 1 1 1 1 4 2 5 1 1 2 1 5 3 4 1
 5 4 1 3 3 1 4 4 5 3 1 1 3 3 3 1 1 5 4 2 5 1 1 5 5 1 4 2 2 5 3 1 1 3 3 5 3 3 2 4 3 2 5 2 5 4 5 4 3 2 4 3 5 1 2 2 4 3 1 5 5 1 3 1 3 2 2 4 5 4 2 3 2 
 3 4 1 3 4 2 5 4 4 2 2 1 4 1 5 1 5 4 3 3 3 3 3 5 2 1 5 5 3 5 2 1 1 4 2 2 5 1 4 3 3 4 4 2 3 2 1 3 1 5 2 1 5 1 3 1 4 2 4 5 1 4 5 5 3 5 1 5 4 1 3 4 1 1 4 5 5 2 1 3 3 */
// Sanitised data input
// Thought of a more efficient simulation using maps where you process each group of numbers at once, leading to only 10 operations needed on each cycle

void solve() {
    map<ll,ll> numbers;
    for (int i = 0; i < 10; i++)
        numbers[i] = 0;
    for (ll i = 0; i < 300; i++) {
        ll a;
        cin >> a;
        numbers[a]++;
    }

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                numbers[9] += numbers[0];
                numbers[7] += numbers[0];
                numbers[0] = 0;
            } else {
                numbers[j-1] += numbers[j];
                numbers[j] = 0;
            }
        }
    }
    ll out = 0;
    for (int i = 0; i < 10; i++)
        out += numbers[i];
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}