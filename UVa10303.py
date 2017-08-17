import sys
Catalan=[1, 1]
for i in range(2, 1001):
    Catalan.append(0)
    for j in range(i):
        Catalan[i]+=Catalan[j]*Catalan[i-1-j]
while True:
    s=sys.stdin.readline()
    if not s:
        break
    s=int(s)
    print(Catalan[s])
