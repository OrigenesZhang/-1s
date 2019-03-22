import sys
while True:
    N=sys.stdin.readline()
    if not N:
        break
    N=int(N)
    if not N:
        print(1)
    else:
        print(N*(N-1)+2)
