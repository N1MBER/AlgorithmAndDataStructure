#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> chains[501];
int path[501];
int S, F;

int getPath(int pos);

int main() {

    int n, m;

    cin >> n >> m;
    pair<int, int> gas_pipeline;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        gas_pipeline = make_pair(v, w);
        chains[u].push_back(gas_pipeline);
    }

    for (int i = 0; i < 501; i++)
        path[i] = -1;

    cin >> S >> F;

    int result = getPath(S);
    if (result == -2)
        cout << "No solution" << endl;
    else
        cout << result << endl;
    return 0;
}

int getPath(int number_node) {
    if (number_node == F)
        return 0;
    else {
        if (path[number_node] == -1) {
            path[number_node] = -2;
            for (int i = chains[number_node].size() - 1; i >= 0; --i) {
                int branch = getPath(chains[number_node][i].first);
                if (branch != -2) {
                    branch += chains[number_node][i].second;
                    path[number_node] = max(path[number_node], branch);
                }
            }
        }
        return path[number_node];
    }
}