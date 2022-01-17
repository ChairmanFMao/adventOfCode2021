#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* 3 1 5 4 4 4 5 3 4 4 1 4 2 3 1 3 3 2 3 2 5 1 1 4 4 3 2 4 2 4 1 5 3 3 2 2 2 5 5 1 3 4 5 1 5 5 1 1 1 4 3 2 3 3 3 4 4 4 5 5 1 3 3 5 4 5 5 5 1 1 2 4 
3 4 5 4 5 2 2 3 5 2 1 2 4 3 5 1 3 1 4 4 1 3 2 3 2 4 5 2 4 1 4 3 1 3 1 5 1 3 5 4 3 1 5 3 3 5 4 2 3 4 1 2 1 1 4 4 4 3 1 1 1 1 1 4 2 5 1 1 2 1 5 3 4 1
 5 4 1 3 3 1 4 4 5 3 1 1 3 3 3 1 1 5 4 2 5 1 1 5 5 1 4 2 2 5 3 1 1 3 3 5 3 3 2 4 3 2 5 2 5 4 5 4 3 2 4 3 5 1 2 2 4 3 1 5 5 1 3 1 3 2 2 4 5 4 2 3 2 
 3 4 1 3 4 2 5 4 4 2 2 1 4 1 5 1 5 4 3 3 3 3 3 5 2 1 5 5 3 5 2 1 1 4 2 2 5 1 4 3 3 4 4 2 3 2 1 3 1 5 2 1 5 1 3 1 4 2 4 5 1 4 5 5 3 5 1 5 4 1 3 4 1 1 4 5 5 2 1 3 3 */
// Sanitised data input

void solve() {
    vector<int> numbers;
    for (int i = 0; i < 300; i++) {
        int a;
        cin >> a;
        numbers.push_back(a);
    }

    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < numbers.size(); j++) {
            if (numbers[j] == 0) {
                numbers[j] = 6;
                numbers.push_back(9);
            }
            else
                numbers[j]--;
        }
    }
    cout << numbers.size() << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}