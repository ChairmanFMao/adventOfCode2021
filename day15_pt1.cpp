#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

struct node {
    int value,
    int x,
    int y
};

bool nodeCompare(node first, node second) {
    return first.value < second.value;
}

string values[10];
priority_queue<node, vector<node>,nodeCompare> processing;

void dijkstra() {
    while (!processing.empty()) {
        node current = processing.top();
        processing.pop();
        if (current.x == 9 && current.y == 9) {
            cout << current.value << "\n";
            return;
        }
        if (current.x != 0) {
            node xZero;
            xZero.value = current.value + values[current.y][current.x-1] - 48;
            xZero.x = current.x-1;
            xZero.y = current.y;
            processing.push(xZero);
        }
        if (current.x != 10) {
            node xMax;
            xMax.value = current.value + values[current.y][current.x+1] - 48;
            xMax.x = current.x+1;
            xMax.y = current.y;
            processing.push(xMax);
        }
        if (current.y != 0) {
            node yZero;
            yZero.value = current.value + values[current.y-1][current.x] - 48;
            yZero.x = current.x;
            yZero.y = current.y-1;
            processing.push(yZero);
        }
        if (current.y != 10) {
            node yMax;
            yMax.value = current.value + values[current.y+1][current.x] - 48;
            yMax.x = current.x;
            yMax.y = current.y+1;
            processing.push(yMax);
        }
    }
}

void solve() {
    ifstream infile;
    infile.open(".\\day15_exampleinput.txt");
    if (!infile)
        exit(1);
    
    for (int i = 0; i < 10; i++)
        infile >> values[i];

    node head;
    head.value = values[0][0] - 48;
    head.x = 0;
    head.y = 0;
    processing.push(head);
    dijkstra();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}