#include <bits/stdc++.h>
using namespace std;

string Delete_Vowel(string s) {
    string cs = "";
    string vowel = "aeiou";
    for(int i = 0; i < s.size(); i++) {
        bool flag = true;
        for(int j = 0; j < vowel.size(); j++) {
            if (s[i] == vowel[j]) {
                flag = false;
            }
        }
        if (flag) {
            cs += s[i];
        }
    }
    return cs;
}

int main() {
    int N;
    string s1, s2;
    cin >> N;
    cin >> s1 >> s2;
    
    if (s1[0] != s2[0] || s1[s1.size() - 1] != s2[s2.size() - 1]) {
        cout << "NO\n";
        return 0;
    }
    
    string s3 = Delete_Vowel(s1);
    string s4 = Delete_Vowel(s2);
    if (s3 != s4) {
        cout << "NO\n";
        return 0;
    }
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 != s2) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    
    return 0;
}




