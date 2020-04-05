и#include <iostream>

using namespace std;

int counts[10000], numbers[10000],n;
int min_value = INT_MAX;
int max_value = INT_MIN;
int min_index = -1;
int max_index = -1;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> counts[i];
        numbers[i] = i + 1;
        if(counts[i] >= max_value){
            max_value = counts[i];
            max_index = i;
        }
        if(counts[i] < min_value){
            min_value = counts[i];
            min_index = i;
        }
    }
    while (min_index != max_index && min_value != INT_MAX) {
        cout << numbers[max_index] << " " << numbers[min_index] << " ";
        counts[max_index]--;
        counts[min_index]--;
        max_value = INT_MIN;
        min_value = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (counts[i] != 0 && counts[i] >= max_value) {
                max_value = counts[i];
                max_index = i;
            }
            if (counts[i] != 0 && counts[i] < min_value) {
                min_value = counts[i];
                min_index = i;
            }
        }
    }
    for (int i = 0; i < max_value; i++)
        cout << numbers[max_index] << endl;
    return 0;
}
