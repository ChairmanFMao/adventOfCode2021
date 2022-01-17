#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

// Restarting from scratch after 2 hours of not getting anywhere
// I was just being stupid for so long, my array approach would've worked and I didn't need to make this fancy queue system to solve the problem
queue<pair<int,int>> points;

void fold(char plane, int line) {
    int length = points.size();
    if (plane == 'y') {
        for (int i = 0; i < length; i++) {
            pair<int,int> current = points.front();
            points.pop();
            if (current.second < line) {
                points.push(current);
                continue;
            }
            if (line + line - current.second < line && line + line - current.second >= 0)
                points.push({current.first, line + line - current.second});
        }
    } else {
        for (int i = 0; i < length; i++) {
            pair<int,int> current = points.front();
            points.pop();
            if (current.first < line) {
                points.push(current);
                continue;
            }
            else if (line + line - current.first < line && line + line - current.first >= 0)
                points.push({line + line - current.first, current.second});
        }
    }
}

void removeDupe() {
    set<pair<int,int>> occured;
    int length = points.size();
    for (int i = 0; i < length; i++) {
        pair<int,int> current = points.front();
        points.pop();
        if (occured.count(current) == 0) {
            points.push(current);
            occured.insert(current);
        }
    }
}

void printOut() {
    set<pair<int,int>> occured;
    int length = points.size();
    for (int i = 0; i < length; i++) {
        occured.insert(points.front());
        points.pop();
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 40; j++) {
            if (occured.count({j,i}) == 1)
                cout << "#";
            else
                cout << ".";
        }
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream inputText;
    inputText.open(".\\day13_input.txt");
    for (int i = 0; i < 887; i++) {
        int x, y;
        inputText >> x >> y;
        points.push({x,y});
    }

    // I had an error here where I was only reading 10 of the 12 fold inputs and it took me roughly 3 hours to debug it, I feel so stupid yet also so extatic
    for (int i = 0; i < 12; i++) {
        char plane;
        int line;
        inputText >> plane >> line;
        fold(plane, line);
        removeDupe();
    }

    printOut();
}