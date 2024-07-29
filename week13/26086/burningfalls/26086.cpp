#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MAX 100001

deque<int> dq;
vector<pair<int, int>> v(MAX);
bool flag = true;

void Func(int sidx, int eidx) {
    for(int i = sidx; i < eidx; i++) {
        if (v[i].first == 0) {
            if (flag) {
                dq.push_back(v[i].second);
            } else if (!flag) {
                dq.push_front(v[i].second);
            }
        } else if (v[i].first == 1) {
            continue;
        } else if (v[i].first == 2) {
            flag = !flag;
        }
    }
}

int main() {
    FASTIO;
    int N, Q, K;
    cin >> N >> Q >> K;

    int sort_idx = -1;

    for(int i = 0; i < Q; i++) {
        int order, p;
        cin >> order;
        if (order == 0) {
            cin >> p;
            v[i] = {0, p};
        } else if (order == 1) {
            v[i] = {1, 0};
            sort_idx = i;
        } else if (order == 2) {
            v[i] = {2, 0};
        }
    }
    
    if (sort_idx != -1) {
        Func(0, sort_idx);
        
        sort(dq.begin(), dq.end());
        flag = false;
        
        Func(sort_idx + 1, Q);
    } else if (sort_idx == -1) {
        Func(0, Q);
    }
    
    cout << (flag ? dq[dq.size() - K] : dq[K - 1]) << "\n";
    
    return 0;
}




