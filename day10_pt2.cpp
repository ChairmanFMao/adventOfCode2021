#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> scores;

void solve() {
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
        else
            return;
    }
    ll score = 0;
    while (characters.size() > 0) {
        score *= 5;
        score += characters.top() == '(' ? 1 : characters.top() == '[' ? 2 : characters.top() == '{' ? 3 : 4;
        characters.pop();
    }
    scores.push_back(score);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t = 98;
    for (int i = 1; i <= t; ++i)
        solve();
    sort(scores.begin(), scores.end());
    // Ran it to output the length and there are 49 strings that this happens to, so the 24 index(25th element) will be the midpoint and have the middle score
    cout << scores[24] << "\n";
}