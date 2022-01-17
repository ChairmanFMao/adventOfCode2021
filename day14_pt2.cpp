#include <bits/stdc++.h>
#include <fstream>
#define ll long long
using namespace std;

// Turns out brute force takes too long and wouldn't work
// 516665100550 too low apparently
// 8156896726606 is current output but it is just not right
// Attempted to change the code, now getting bad_alloc errors, idk why
// I think that I may have been double counting the letters idk tho
// 10002813279338 was output but its wrong, idk if rounding error

map<string,string> mapping;
map<string,ll> patternOccurs;
vector<string> diffPatterns;
set<string> uniqueStrings;

void initialOccurs(string s) {
    for (ll i = 0; i < s.size()-1; i++)
        patternOccurs[s.substr(i,2)]++;
}

void process() {
    vector<pair<string,ll>> nextOccurs;
    for (ll i = 0; i < diffPatterns.size(); i++) {
        if (patternOccurs[diffPatterns[i]] > 0) {
            // Was adding the whole string not just the characters
            string firstpart = diffPatterns[i][0] + mapping[diffPatterns[i]], secondpart = mapping[diffPatterns[i]] + diffPatterns[i][1];
            nextOccurs.push_back({firstpart,patternOccurs[diffPatterns[i]]});
            nextOccurs.push_back({secondpart,patternOccurs[diffPatterns[i]]});
            uniqueStrings.insert(firstpart);
            uniqueStrings.insert(secondpart);
            patternOccurs[diffPatterns[i]] = 0;
        }
    }
    for (int i = 0; i < nextOccurs.size(); i++)
        patternOccurs[nextOccurs[i].first] += nextOccurs[i].second;
}

int main(void) {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    ifstream textInput;
    textInput.open(".\\day14_input.txt");
    if (!textInput)
        exit(1);
    
    string text;
    textInput >> text;
    // Should be 100
    for (int i = 0; i < 100; i++) {
        string both, discard, processed;
        textInput >> both >> discard >> processed;
        mapping[both] = processed;
        diffPatterns.push_back(both);
    }
    textInput.close();
    initialOccurs(text);

    for (int i = 0; i < 40; i++)
        process();
    
    set<char> seen;
    map<char,ll> occurances;
    // diffPatterns has a size of 0
    for (int i = 0; i < diffPatterns.size(); i++) {
        occurances[diffPatterns[i][0]] += patternOccurs[diffPatterns[i]];
        occurances[diffPatterns[i][1]] += patternOccurs[diffPatterns[i]];
        seen.insert(diffPatterns[i][0]);
        seen.insert(diffPatterns[i][1]);
    }
    // The error is somewhere in the code underneath
    vector<char> seenVector;
    seenVector.insert(seenVector.begin(), seen.begin(), seen.end());
    ll big = occurances[seenVector[0]], small = occurances[seenVector[0]];
    char biggest = ' ', smallest = ' ';
    for (int i = 0; i < seenVector.size(); i++) {
        if (occurances[seenVector[i]] > big) {
            big = occurances[seenVector[i]];
            biggest = seenVector[i];
        } if (occurances[seenVector[i]] < small) {
            small = occurances[seenVector[i]];
            smallest = seenVector[i];
        }
    }
    // This is due to the fact that 'F' (smallest) appears at the end of the original string;
    // This needs to be done as F will have one appearance in pairs where is it not doubled, the same would happen for 'V'
    // However we disreguard this as it's occurances is somewhere in the middle of the characters
    // I had to check this and this solution here is not generalised
    smallest--;
    cout << (big-small)/2 << "\n"; 
}