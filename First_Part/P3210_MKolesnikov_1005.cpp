#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int rec(int i, int sum0, int sum1, const vector<int> &v);
int main() {
    int test;// c - count, test - count of test
    cin >> test;
    vector<int> vector(test);
    for (int i = 0; i <test;i++){
        cin >> vector[i] ;
    }
    if(test == 1){
        cout << vector[test-1] << endl;
    } else
        cout << rec(test-2, vector[test-1],0,vector) << endl;
    return 0;
}

int rec(int test, int sum0, int sum1, const vector<int> &vector) {
    if (test == 1) {
        if(sum0 >sum1)
            return abs(sum1-sum0+vector[test-1]);
        else
            return abs(sum1-sum0-vector[test-1]);
    } else {
        return min(rec(test - 1, sum0 + vector[test], sum1, vector), rec(test - 1, sum0, sum1 + vector[test], vector));
    }
}
