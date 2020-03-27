#include <iostream>
#include <climits>
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

int n, x[10000], y[10000], numbers[10000] ;
int y_min = INT_MAX;
int min_number = 9999;
double angle[10000];

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        numbers[i] = i+1;
        if (y[i] < y_min || (y[i] == y_min && x[i] < x[min_number])){
            y_min = y[i];
            min_number = i;
        }
    }
    swap(x[0],x[min_number]);
    swap(y[0],y[min_number]);
    swap(numbers[0], numbers[min_number]);
    swap(angle[0],angle[min_number]);
    for (int j = 1; j < n; ++j) {
        if (x[j] == x[0]){
            angle[j] = M_PI / 2;
        } else if(y[j] == y[0]){
            angle[j] = 0;
        }else{
            angle[j] = atan((double)(y[j]-y[0])/(double)(x[j]-x[0]));
        }
        if (angle[j] < 0)
            angle[j] += 2*M_PI;
    }
    for(int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (angle[i] > angle[j]) {
                swap(x[i],x[j]);
                swap(y[i],y[j]);
                swap(numbers[i], numbers[j]);
                swap(angle[i],angle[j]);
            }
        }
    }
    cout << numbers[0] << " " << numbers[n/2] << endl;
}