#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(string start) {
    string end = "12345678x";

    queue<string> q;
    unordered_map<string, int> d;

    q.push(start);
    d[start] = 0;

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

    while (q.size()) {
        auto t = q.front();
        q.pop();

        int distance = d[t];
        if (t == end) return distance;

        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(t[k], t[a * 3 + b]);

                if (!d.count(t)) {
                    d[t] = distance + 1;
                    q.push(t);
                }

                swap(t[k], t[a * 3 + b]);
            }
        }
    }
    return -1;
}

int main() {
    string start;
    for (int i = 0; i < 9; i++) {
        char c;
        cin >> c;
        start += c;
    }

    cout << bfs(start) << endl;
    return 0;
}