def out(cur, width, upp):
    if cur<upp:
        if d[cur]>cur+1:
            totblk=width-sum[d[cur]-1]+sum[cur-1]
            blk=totblk//(d[cur]-cur-1)
            diff=(blk+1)*(d[cur]-cur-1)-totblk
            cnt=0
            print(wordlst[cur], end="")
            for i in range(cur+1, d[cur]):
                for j in range(0, blk):
                    print(' ', end="")
                cnt+=1
                if cnt>diff:
                    print(' ', end="")
                print(wordlst[i], end="")
            print()
        else:
            print(wordlst[cur])
        out(d[cur], width, upp)
while True:
    width=int(input())
    if width==0:
        break
    cnt=1
    wordlst=[""]
    while True:
        tmp=input()
        if tmp=="":
            break
        curline=tmp.split()
        cnt+=len(curline)
        wordlst+=curline
    length=[0.5]
    for i in range(1, cnt):
        length.append(len(wordlst[i]))
    sum=[0]
    for i in range(1, cnt):
        sum.append(sum[i-1]+length[i])
    dp=[0 for i in range(0, cnt+1)]
    d=[dp[i] for i in range(0, cnt+1)]
    for i in range(cnt-1, 0, -1):
        dp[i]=dp[i+1]+500
        d[i]=i+1
        for j in range(i+1, cnt):
            if sum[j]-sum[i-1]+j-i>width:
                break
            totblk=width-sum[j]+sum[i-1]
            blk=totblk//(j-i)
            diff=(blk+1)*(j-i)-totblk
            cost=(j-i-diff)*blk*blk+diff*(blk-1)*(blk-1)
            if dp[i]>=dp[j+1]+cost:
                dp[i]=dp[j+1]+cost
                d[i]=j+1
    out(1, width, cnt)
    print()
#这题的IO好难受
#处于用C++ IO吃屎和python dp吃屎的两难中
