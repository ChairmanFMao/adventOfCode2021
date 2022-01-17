#include <bits/stdc++.h>
using namespace std;
#define ll long long

// bcfdga bacgf bdg adgc bdefa fcedgb dagfb ebcadgf dg bcfeag | ebfad aefbd abecgf gcefadb
// Currently causing errors, everything else works fine
// Hangs on the final cycle of j in the first loop

struct number {
    int value;
    int lines;
    string alpha;
};

void solve() {
    int counter = 0;
    // Change it to 200 later
    for (int i = 0; i < 1; i++) {
        map<int, string> corresponding;
        vector<number> numbers(10);
        for (int j = 0; j < 10; j++) {
            string a;
            // Appears to be an issue with this line, cin?
            cin >> a;
            sort(a.begin(), a.end());
            number value;
            value.lines = a.size();
            value.alpha = a;
            value.value = -1;
            if (value.lines == 2) {
                value.value = 1;
                corresponding[value.value] = a;
            } else if (value.lines == 3) {
                value.value = 7;
                corresponding[value.value] = a;
            } else if (value.lines == 4) {
                value.value = 4;
                corresponding[value.value] = a;
            } else if (value.lines == 7) {
                value.value = 8;
                corresponding[value.value] = a;
            }
            numbers[j] = value;
        }
        int ptr = 0;
        vector<number> sixes(3);
        for (int j = 0; j < 10; j++) {
            if (numbers[j].lines == 6) {
                sixes[ptr] = numbers[j];
                ptr++;
            }
        }
        for (int j = 0; j < 3; j++) {
            string four = corresponding[4];
            int occur = 0;
            for (int k = 0; k < 4; k++)
                occur += count(sixes[j].alpha.begin(),sixes[j].alpha.end(), four[k]);
            if (occur == 4) {
                corresponding[9] = sixes[j].alpha;
                sixes.erase(sixes.begin()+j);
                break;
            }
        }
        for (int j = 0; j < 2; j++) {
            string seven = corresponding[7];
            int occur = 0;
            for (int k = 0; k < 3; k++)
                occur += count(sixes[j].alpha.begin(),sixes[j].alpha.end(), seven[k]);
            if (occur == 3) {
                corresponding[0] = sixes[j].alpha;
                sixes.erase(sixes.begin()+j);
                break;
            }
        }
        corresponding[6] = sixes[0].alpha;
        int ptr2 = 0;
        vector<number> fives(3);
        for (int j = 0; j < 10; j++) {
            if (numbers[j].lines == 5) {
                fives[ptr2] = numbers[j];
                ptr2++;
            }
        }
        for (int j = 0; j < 3; j++) {
            string seven = corresponding[7];
            int occur = 0;
            for (int k = 0; k < 3; k++)
                occur += count(fives[j].alpha.begin(),fives[j].alpha.end(), seven[k]);
            if (occur == 3) {
                corresponding[3] = fives[j].alpha;
                sixes.erase(fives.begin()+j);
                break;
            }
        }
        for (int j = 0; j < 2; j++) {
            string nine = corresponding[9];
            int occur = 0;
            for (int k = 0; k < 6; k++)
                occur += count(fives[j].alpha.begin(),fives[j].alpha.end(), nine[k]);
            if (occur == 5) {
                corresponding[5] = fives[j].alpha;
                fives.erase(fives.begin()+j);
                break;
            }
        }
        corresponding[2] = fives[0].alpha;

        map<string, int> scores;
        for (int i = 0; i < 10; i++)
            scores[corresponding[i]] = i;

        string placeholder;
        cin >> placeholder;

        string sum = "";
        for (int j = 0; j < 4; j++) {
            string a;
            cin >> a;
            sort(a.begin(),a.end());
            sum += to_string(scores[a]);
        }
        cout << sum << "\n";
        counter += stoi(sum);
    }
    cout << counter << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    //cin.tie(0);

    solve();
}