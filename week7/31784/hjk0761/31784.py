n, k = map(int, input().split())

s = input()
result = ""

for i in range(len(s)):
    index = (ord('Z') - ord(s[i]) + 1) % 26

    if i == len(s) - 1:
        temp = (ord(s[i]) - ord('A') + k) % 26 + ord('A')
        result += chr(temp)
    else:
        if k >= index:
            k -= index
            result += 'A'
        else:
            result += s[i]

print(result)
