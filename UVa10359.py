#这题要讨论n=0这个没什么意义的情况有点坑
import sys
c=[[], [1, 1]]
for i in range(2, 251):
    c.append([1])
    for j in range(1, i):
        c[i].append(c[i-1][j-1]+c[i-1][j])
    c[i].append(1)
f=[1, 1, 3]
for i in range(3, 251):
    f.append(0)
    for j in range(i//2, -1, -1):
        f[i]+=c[i-j][j]*(1<<j)
while True:
    N=sys.stdin.readline()
    if not N:
        break
    print(f[int(N)])
