#include <iostream>
#include <algorithm>

using namespace std;

int n;
char charA, charB;
int intA, intB;
int useNow[100001];
int useNot[100001];
int useBefore[100001];
int answer;

int cal(int now, char a, int b) {
    if (a == '+') {
        return now + b;
    }
    if (a == '-') {
        return now - b;
    }
    if (a == '*') {
        return now * b;
    }
    if (a == '/') {
        return now / b;
    }
}

int better(int now, char cA, int iA, char cB, int iB) {
    int calA = cal(now, cA, iA);
    int calB = cal(now, cB, iB);
    return max(calA, calB);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin >> charA >> intA;
    cin >> charB >> intB;
    useNow[0] = 1;
    useNot[0] = max(better(1, charA, intA, charB, intB), 0);
    useBefore[0] = 1;

    for (int i = 1; i < n; i++) {
        cin >> charA >> intA;
        cin >> charB >> intB;

        useNot[i] = useNot[i - 1] > 0 ? better(useNot[i - 1], charA, intA, charB, intB) : 0;
        useNow[i] = useNot[i - 1];
        useBefore[i] = max(
                useNow[i - 1] > 0 ? better(useNow[i - 1], charA, intA, charB, intB) : 0,
                useBefore[i - 1] > 0 ? better(useBefore[i - 1], charA, intA, charB, intB) : 0);
        if (useNot[i] <= 0 && useNow[i] <= 0 && useBefore[i] <= 0) {
            cout << "ddong game";
            return 0;
        }
    }
    answer = max(useNot[n - 1], useNow[n - 1]);
    answer = max(answer, useBefore[n - 1]);

    cout << answer;
    return 0;
}
