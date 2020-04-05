#include <iostream>

using namespace std;

long long n, x[100001], y[100001];

void quick_sort(long long *, int, int);

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    quick_sort(x, 0, n - 1);
    quick_sort(y, 0, n - 1);
    long long res_x = 0, res_y =0;
    for(int i = 1; i < n; i++){
        res_x += (x[i] - x[i - 1]) * i * (n-i) * 2;
        res_y += (y[i] - y[i - 1]) * i * (n-i) * 2;
    }
    long result = (res_x + res_y) / (n * (n - 1));
    cout << result << endl;
    return 0;
}

void quick_sort(long long *arr, int left, int right){
    int i, j;
    long long mean;
    i = left, j = right;
    mean = arr[(left + right)/2];
    while(i <= j){
        while (arr[i] < mean)
            i++;
        while (arr[j] > mean)
            j--;
        if (i > j)
            break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    if (left < j)
        quick_sort(arr, left, j);
    if (i < right)
        quick_sort(arr, i, right);
}