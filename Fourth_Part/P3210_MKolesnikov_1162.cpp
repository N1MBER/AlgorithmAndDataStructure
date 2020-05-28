#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct element
{
    int a, b;
    double r, c;
};

vector<element> currencies;
double nodes[101];
int N, M, S;
double V;

bool getProfit(){
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < currencies.size(); j++) {
            nodes[currencies[j].b] = max((nodes[currencies[j].a] - currencies[j].c) * currencies[j].r, nodes[currencies[j].b]);
        }
    }
    for (int i = 0; i < currencies.size(); i++)
        if ((nodes[currencies[i].a] - currencies[i].c)*currencies[i].r > nodes[currencies[i].b])
        {
            return true;
        }
    return false;
}

int main()
{
    cin >> N >> M >> S >> V;
    nodes[S] = V;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        double rab, cab, rba, cba;
        cin >> a >> b >> rab >> cab >> rba >> cba;
        currencies.push_back({ a, b, rab, cab });
        currencies.push_back({ b, a, rba, cba });
    }
    if(getProfit())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}