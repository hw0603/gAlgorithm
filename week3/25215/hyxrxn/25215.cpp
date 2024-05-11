#include <iostream>
using namespace std;

int arr[3000] = {0};

bool isUpper(char c) {
    return c <= 'Z';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    int index = 0;
    arr[index] = 1;
    for (int i = 1; i < s.length(); i++) {
        if (isUpper(s[i]) == isUpper(s[i - 1])) {
            arr[index]++;
        } else {
            index++;
            arr[index] = 1;
        }
    }

//    for (int i = 0; i <= index; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;

    int num = arr[0];
    bool frontStar;
    if (arr[0] == 1 && isUpper(s[0])) {
        num++;
        frontStar = true;
    } else {
        frontStar = false;
    }

    for (int i = 1; i <= index; i++) {
        num += arr[i];
        if (frontStar) { // 앞을 *로 바꿨으면 추가로 누를 버튼 없음
            frontStar = false;
        }
        else if (arr[i] > 1) { // 한 개 이상이면 <> 눌러야 함
            num++;
            frontStar = false;
        }
        else if (arr[i] == 1) { // 한 개면 *로 바꿈
            num++;
            frontStar = true;
        }
        //cout << i << " " << num << endl;
    }

    if (isUpper(s[0]) && arr[0] != 1) { // 맨 앞이 대문자 여러 개면 <> 누르고 시작
        num++;
    }

    cout << num;

    return 0;
}


// iLoveINHA 11
// i l* ove <>INHA

// iLoveINHAUNI
// i <>

// ConquerThePlanet 19
// c* onquer t* he p* lanet

// aAbc 5
// a a* bc

// AaBC 6
// a* a <>bc
// <>A a* bc

// aAAbb 7
// a <>aa <>bb

// AaaBB 7
// a* aa <>bb
// <>A a*a* <>bb

// PQPhdeQ 10
// <>pqp <>hde q*

// bbdIiF 8
// bbd i* i f*

// afKjAOnnMjjjEQeAC 23
// af k* j <>ao <>nn m* jjj <>eq e* ac
