import sys
fib=[1, 2]
for i in range(2, 1001):
    fib.append(fib[i-1]+fib[i-2])
while True:
    N=sys.stdin.readline()
    if not N:
        break
    N=int(N)
    print(fib[N])
