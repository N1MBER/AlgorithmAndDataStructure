#include <algorithm>
#include <map>
#include <set>
#include <iostream>

using namespace std;
typedef pair<int, int> pairs;
int N, M, K, ans;

bool compare_first(pairs a, pairs b);
bool compare_second(pairs a, pairs b);

pairs days[180000];
set<pairs> set_pairs;

int main() {
    cin >> N >> M >> K;
    for (int i = 0, x, y; i < K; ++i) {
        cin >> x >> y;
        days[i] = make_pair(x, y);
    }
    for (int i = 1; i <= M; i++) {
        days[K++] = make_pair(0, i);
        days[K++] = make_pair(N + 1, i);
    }
    for (int i = 1; i <= N; i++) {
        days[K++] = make_pair(i, 0);
        days[K++] = make_pair(i, M + 1);
    }
    sort(days, days + K, compare_first);
    int diff;
    for (int i = 0; i+1 < K ; i++) {
        diff = days[i + 1].second - days[i].second;
        if (days[i].first == days[i + 1].first && diff >= 2) {
            if (diff == 2) {
                pairs element = make_pair(days[i].first, days[i].second + 1);
                set_pairs.insert(element);
            }
            else
                ++ans;
        }
    }
    sort(days, days + K, compare_second);
    for (int i = 0;i + 1<K;++i) {
        diff = days[i + 1].first - days[i].first;
        if (days[i].second == days[i + 1].second && diff >= 2) {
            if (diff == 2) {
                if (set_pairs.find(make_pair(days[i].first + 1, days[i].second)) != set_pairs.end())
                    ++ans;
            }
            else
                ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}


bool compare_first(pairs a, pairs b) {
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}

bool compare_second(pairs a, pairs b) {
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}