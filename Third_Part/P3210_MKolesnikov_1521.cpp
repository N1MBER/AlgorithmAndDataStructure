#include <iostream>

using namespace std;

int choose_solder(int*, int, int);

int main() {
    int n, k;
    int tree_size = 1;
    cin >> n >> k;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    while (tree_size < n) {
        tree_size *= 2;
    }
    int* tree = new int[2 * tree_size];
    for (int i = 0; i < n; i++)
        tree[tree_size + i] = i + 1;
    for (int i = tree_size - 1; i > 0; i--) {
        if (2 * i >= tree_size) {
            tree[i] = 0;
            if (tree[2 * i] != 0)
                tree[i]++;
            if (tree[2 * i + 1] != 0)
                tree[i]++;
        }
        else
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    int previous = 0;
    while (n > 0) {
        previous = (previous + k - 1) % n;
        n--;
        int index = choose_solder(tree, previous + 1, tree_size);
        cout << index << " ";
        tree[tree_size + index - 1] = 0;
        int j = tree_size + index - 1;
        while (j > 1) {
            j /= 2;
            tree[j]--;
        }
    }

    return 0;
}

int choose_solder(int tree[], int m, int tree_size) {
    int x = 1;

    while (2 * x < tree_size) {
        if (tree[x * 2] >= m) {
            x *= 2;
        }
        else {
            m -= tree[x * 2];
            x = x * 2 + 1;
        }
    }
    if (tree[x] == 2)
        return tree[2 * x + m - 1];
    else
    if (tree[2 * x + 1] != 0)
        return tree[2 * x + 1];
    else
        return tree[2 * x];
}