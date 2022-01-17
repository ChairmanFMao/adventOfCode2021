#include <bits/stdc++.h>
using namespace std;
#define ll long long

// KF sr OO vy start FP FP end vy mi vy KF vy na start sr FP lh sr FP na FP end KF na mi lh KF end lh na start wp KF mi KF vy sr vy lh sr mi
// Sanitised data input, there are 21 pairs, there are 11 different nodes
// I got this code to work by adding backtracking of a kind by incrementing the visited values and then decrementing them
// Code took a lot of tweaking but I managed to get it working

struct Node {
    bool big = 0;
    int visited = 0;
    vector<string> connections;
};

ll routes = 0;
map<string,Node> relation;

void dfs(string from) {
    if (relation[from].visited > 1 && relation[from].big == 0)
        return;
    if (from == "end") {
        routes++;
        return;
    }
    for (int i = 0; i < relation[from].connections.size(); i++) {
        relation[relation[from].connections[i]].visited++;
        dfs(relation[from].connections[i]);
        relation[relation[from].connections[i]].visited--;
    }
}

bool up(string a) {
    for (int i = 0; i < a.size(); i++)
        if (!isupper(a[i]))
            return false;
    return true;
}

void solve() {
    set<string> seen;
    vector<pair<string,string>> edges;
    for (int i = 0; i < 21; i++) {
        string a, b;
        cin >> a >> b;
        edges.push_back({a,b});
        if (seen.count(a) == 0) {
            Node node;
            if (up(a))
                node.big = 1;
            relation[a] = node;
        } if (seen.count(b) == 0) {
            Node node;
            if (up(b))
                node.big = 1;
            relation[b] = node;
        }
        seen.insert(a);
        seen.insert(b);
    }
    for (int i = 0; i < 21; i++) {
        relation[edges[i].first].connections.push_back(edges[i].second);
        relation[edges[i].second].connections.push_back(edges[i].first);
    }

    // Let the search begin!
    relation["start"].visited = 1;
    dfs("start");

    cout << routes << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}