#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Had an idea, need to evaluate the most common starting number after deleting numbers from the queue
// This was due to reading the questions properly
// This epicly worked

char common(queue<string> q, int pos, int bias) {
    int ones = 0, zeros = 0, length = q.size();
    for (int i = 0; i < length; i++) {
        string a = q.front();
        q.pop();
        if (a[pos] == '0')
            zeros++;
        else
            ones++;
    }
    if (bias == 1)
        return ones >= zeros ? '1' : '0';
    else
        return ones >= zeros ? '0' : '1';
}

ll counter(queue<string> q, int bias) {
    for (int i = 0; i < 12; i++) {
        char more = common(q, i, bias);
        int length = q.size();
        if (length == 1)
            return stoi(q.front(), 0, 2);
        for (int j = 0; j < length; j++) {
            string a = q.front();
            q.pop();
            if (a[i] == more)
                q.push(a);
        }
    }
    return 0;
}

void solve() {
    string a;
    cin >> a;
    queue<string> ox, co;
    while (a != "stop") {
        ox.push(a);
        co.push(a);
        cin >> a;
    }
    
    cout << counter(ox, 1) * counter(co, 0) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}