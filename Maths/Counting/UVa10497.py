res=[0, 0, 1, 2]
for i in range(4, 801):
    res.append((i-1)*(res[-1]+res[-2]))
while True:
    N=int(input())
    if N==-1:
        break
    print(res[N])
