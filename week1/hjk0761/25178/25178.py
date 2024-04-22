n = int(input())
origin = input()
changed = input()

vowels = ['a', 'e', 'i', 'o', 'u']

def rearrange(s, d):
    sorted_origin = sorted(origin)
    sorted_changed = sorted(changed)
    if sorted_origin == sorted_changed:
        return True
    return False

def firstAndLast(s, d):
    if s[0] == d[0] and s[-1] == d[-1]:
        return True
    return False

def isSameWithoutVowel(s, d):
    for c in vowels:
        if c in s:
            s = s.replace(c, "")
        if c in d:
            d = d.replace(c, "")
    print(s, d)
    if s == d:
        return True
    return False

if rearrange(origin, changed) and firstAndLast(origin, changed) and isSameWithoutVowel(origin, changed):
    print("YES")
else:
    print("NO")