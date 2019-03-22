fib=[0, 1, 2]
for i in range(3, 501):
    fib.append(fib[i-1]+fib[i-2])
while True:
    s=input()
    if s=="0 0":
        break
    a, b=s.split()
    a=int(a)
    b=int(b)
    if a:
        l=1
        r=500
        mid=l
        while l+1<r:
            mid=(l+r)>>1
            if fib[mid]>=a and fib[mid-1]<a:
                break
            if fib[mid]>=a:
                r=mid
            else:
                l=mid
        if fib[mid]>=a and fib[mid-1]<a:
            m1=mid
        elif fib[l]>=a:
            m1=l
        else:
            m1=r
    else:
        m1=1
    if fib[m1]<=b:
        r=500
        l=1
        mid=l
        while l+1<r:
            mid=(l+r)>>1
            if fib[mid]<=b and fib[mid+1]>b:
                break
            if fib[mid]>b:
                r=mid
            else:
                l=mid
        if fib[mid]<=b and fib[mid+1]>b:
            m2=mid
        elif fib[r]>b:
            m2=r-1
        else:
            m2=r
        print(m2-m1+1)
    else:
        print(0)
#居然是个打表题...
#一开始用公式算的结果python double丢了好多精度fib[100]以上就有很大的问题
#代码也是公式的代码上改的
#如果python有lower_bound和upper_bound就好了...
