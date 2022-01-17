#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
#define ll long long

// KF sr OO vy start FP FP end vy mi vy KF vy na start sr FP lh sr FP na FP end KF na mi lh KF end lh na start wp KF mi KF vy sr vy lh sr mi
// Sanitised data input, there are 21 pairs, there are 11 different nodes
// I got this code to work by adding backtracking of a kind by incrementing the visited values and then decrementing them
// Just adding the twice boolean to the code from part 1 wasn't that difficult, the difficult part was storing the graph

struct Node {
    bool big = 0;
    int visited = 0;
    vector<string> connections;
};

ll routes = 0;
map<string,Node> relation;
// First is needed here because it only allows the "start" node to be visited once even though it is a small cave the twice can't be used on it
bool first = 1;

// Twice is a boolean that is used to tell if the double use of a small cave has been done on that specific path
void dfs(string from, bool twice) {
    if ((relation[from].visited > 1 && relation[from].big == 0 && twice) || (from == "start" && !first))
        return;
    first = 0;
    if (from == "end") {
        routes++;
        return;
    }
    if (relation[from].visited > 1 && relation[from].big == 0 && !twice)
        twice = 1;
    for (int i = 0; i < relation[from].connections.size(); i++) {
        relation[relation[from].connections[i]].visited++;
        dfs(relation[from].connections[i], twice);
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
    dfs("start", 0);

    cout << routes << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // These auto variables are just to time the program, it takes 1.5-2.0 seconds for execution
    auto start = high_resolution_clock::now();
    solve();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << "\n";
}