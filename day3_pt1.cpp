#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 4138664 I think, idk, timed out rn
// Got it right!

void solve() {
    string a;
    cin >> a;
    int ones[12], zeros[12];
    for (int i = 0; i < 12; i++) {
        ones[i] = 0;
        zeros[i] = 0;
    }
    while (a != "stop") {
        for (int i = 0; i < 12; i++) {
            if (a[i] == '0')
                zeros[i]++;
            else
                ones[i]++;
        }
        cin >> a;
    }
    string most = "", least = "";
    for (int i = 0; i < 12; i++) {
        cout << i << "th values: one - " << ones[i] << " zero - " << zeros[i] << "\n";
        most += ones[i] > zeros[i] ? "1" : "0";
        least += ones[i] > zeros[i] ? "0" : "1";
    }
    // Read documentation for stoi() function, first parameter is the base, second is default 0 or NULL
    // third parameter is the base that the number in the string is in, so by using base 2 we can use
    // the stoi(string to int) function to convert the binary strings to denary
    cout << "most: " << most << " least: " << least << "\n";
    ll mostNumber = stoi(most, 0, 2), leastNumber = stoi(least, 0, 2);
    cout << "most: " << mostNumber << " least: " << leastNumber << "\n";
    cout << mostNumber * leastNumber << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}