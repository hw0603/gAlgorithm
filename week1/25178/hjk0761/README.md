## 25178 - 두라무리 휴지

문자열의 길이가 최대 10^5 이므로 선형탐색을 해도 시간이 부족하지 않겠다고 생각

애너그램인지 확인 -> 문자 기준으로 정렬된 리스트를 확인

첫 글자, 마지막 글자 확인 -> 리스트 인덱싱

모음 제거 시 같은지 확인 -> 순회하면서 모음이 있으면 replace로 공백으로 바꿔준 이후에 비교