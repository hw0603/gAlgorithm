import sys

S = sys.stdin.readline().strip()
_ = ""
print([_:=min(_+ch, ch+_) for ch in S][-1])
