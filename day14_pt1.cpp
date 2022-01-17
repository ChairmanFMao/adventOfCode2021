#include <bits/stdc++.h>
#include <fstream>
#define ll long long
using namespace std;

map<string,string> mapping;

string process(string old) {
    string out = "";
    for (int i = 0 ; i < old.size()-1; i++) {
        out += old[i];
        out += mapping[old.substr(i,2)];
    }
    out += old[old.size()-1];
    return out;
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
    for (int i = 0; i < 100; i++) {
        string both, discard, processed;
        textInput >> both >> discard >> processed;
        mapping[both] = processed;
    }
    textInput.close();
    for (int i = 0; i < 10; i++)
        text = process(text);
    
    set<char> unique;
    map<char,ll> occurs;
    for (ll i = 0; i < text.size(); i++) {
        unique.insert(text[i]);
        occurs[text[i]]++;
    }
    vector<char> characters(unique.begin(), unique.end());
    ll smallest = occurs[characters[0]], biggest = occurs[characters[0]];
    for (ll i = 0; i < characters.size(); i++) {
        if (occurs[characters[i]] < smallest)
            smallest = occurs[characters[i]];
        if (occurs[characters[i]] > biggest)
            biggest = occurs[characters[i]];
    }
    cout << biggest-smallest << "\n";
}