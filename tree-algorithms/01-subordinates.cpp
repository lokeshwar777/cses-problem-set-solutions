/* 777 */

#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VII = vector<VI>;

int subtree_size[200010];
VI graph[200010];

void dfs(int node) {
    for (int child : graph[node]) {
        dfs(child);
        subtree_size[node] += 1 + subtree_size[child];
    }
}

int main() {
    int n;
    cin >> n;

    for (int child = 2; child <= n; ++child) {
        int parent;
        cin >> parent;
        graph[parent].push_back(child);
    }

    dfs(1);
    for (int node = 1; node <= n; node++) cout << subtree_size[node] << " ";
    return 0;
}