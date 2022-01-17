#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve() {
    string s;
    cin >> s;

    stack<char> characters;
    for (int i = 0; i < s.size(); i++) {
        if (characters.size() == 0) {
            characters.push(s[i]);
            continue;
        }
        if (characters.top() == '[' && s[i] == ']' || characters.top() == '{' && s[i] == '}' || characters.top() == '(' && s[i] == ')' || characters.top() == '<' && s[i] == '>') {
            characters.pop();
            continue;
        }
        else if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<')
            characters.push(s[i]);
        else {
            if (s[i] == ')')
                return 3;
            if (s[i] == ']')
                return 57;
            if (s[i] == '}')
                return 1197;
            if (s[i] == '>')
                return 25137;
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t = 98;
    ll errorScore = 0;
    for (int i = 1; i <= t; ++i)
        errorScore += solve();
    cout << errorScore << "\n";
}