import sys
Fib=[1, 2]
for i in range(2, 300):
    Fib.append(Fib[i-1]+Fib[i-2])
f1=input()
f2=input()
while True:
    n1=n2=0
    for i in range(len(f1)):
        if int(f1[-i-1]):
            n1+=Fib[i]
    for i in range(len(f2)):
        if int(f2[-i-1]):
            n2+=Fib[i]
    n1+=n2
    if n1==0:
        print(0, end="")
    else:
        flag=False
        for i in range(299, -1, -1):
            if n1>=Fib[i]:
                print(1, end="")
                flag=True
                n1-=Fib[i]
            else:
                if flag:
                    print(0, end="")
    print()
    s=sys.stdin.readline()
    if not s:
        break
    print()
    f1=input()
    f2=input()
#暴力出奇迹
