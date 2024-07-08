#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n, m;
char info[1001];
int connect[1001];
priority_queue<tuple<int, int, int>> vertex;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> info[i];
        connect[i] = i;
    }
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (info[a] != info[b]) {
            vertex.push({-c, a, b});
        }
    }

    int count = 0;
    int length = 0;
    while (count < n - 1) {
        if (vertex.empty()) {
            cout << -1;
            return 0;
        }
        tuple<int, int, int> t = vertex.top();
        vertex.pop();
        if (connect[get<1>(t)] != connect[get<2>(t)]) {
            int parent = connect[get<1>(t)];
            int child = connect[get<2>(t)];
            for (int i = 1; i <= n; i++) {
                if (connect[i] == child) {
                    connect[i] = parent;
                }
            }
            count++;
            length += get<0>(t);
//            cout << "choose " << get<1>(t) << " " << get<2>(t) << " " << get<0>(t) << endl;
//        } else {
//            cout << "ignore " << get<1>(t) << " " << get<2>(t) << " " << get<0>(t) << endl;
        }
    }

    cout << -length;
    return 0;
}

//5 7
//M W W W M
//5 2 5 -> 25 1 3 4
//5 4 7 -> 245 1 3
//2 5 10 -> no
//1 3 10 -> 235 13
//1 2 12 -> 12345
