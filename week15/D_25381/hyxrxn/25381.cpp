#include <iostream>
#include <algorithm>
using namespace std;

string s;
int countB = 0;
int numA = 0;
int numB = 0;
int answerA = 0;
int answerC = 0;

int main() {
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            countB++;
        }
        if (s[i] == 'B' && numA > 0) {
            numA--;
            answerA++;
        } else if (s[i] == 'A') {
            numA++;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'C' && numB > 0) {
            numB--;
            answerC++;
        } else if (s[i] == 'B') {
            numB++;
        }
    }

    cout << min(answerA + answerC, countB);

    return 0;
}