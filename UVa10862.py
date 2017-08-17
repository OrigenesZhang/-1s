cnt=[0, 1, 3]
for i in range(3, 2001):
    cnt.append(3*cnt[i-1]-cnt[i-2])
while True:
    N=int(input())
    if not N:
        break
    print(cnt[N])
