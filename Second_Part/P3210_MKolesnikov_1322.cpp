#include <iostream>

using namespace std;

int first_char;
int m = 100000;
string str;
int *counts = new int[m];
int *analog;
int sum = 0;
char *result_word;

int main() {
    cin >> first_char;
    cin >> str;
    analog = new int[m];
    result_word = new char [str.length()];
    for (int i = 0; i < m; i++) {
        counts[i]=0;
    }
    for (int j = 0; j < str.length(); j++) {
        counts[str[j]]++;
    }
    for (int l = 0; l < m; l++) {
        sum += counts[l];
        counts[l] = sum - counts[l];
    }
    for(int m = 0; m < str.length(); m++){
        analog[counts[str[m]]] = m;
        counts[str[m]]++;
    }
    int order = analog[first_char-1];
    for (int w = 0; w < str.length() ; w++) {
        result_word[w] = str[order];
        order = analog[order];
    }
    for (int i = 0; i < str.length(); i++){
        cout << result_word[i];
    }
    cout << endl;
    return 0;
}