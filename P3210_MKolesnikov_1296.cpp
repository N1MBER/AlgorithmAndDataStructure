#include <iostream>

using namespace std;

int main() {
    int test,count;
    int result = 0;
    int sum = 0;
    cin >> test;
    for(int j = 0 ; j < test; j++){
        cin >> count;
        sum = max(0,sum+count);
        result = max(result,sum);
    }
    cout << result;
}