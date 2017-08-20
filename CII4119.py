#2008 World Final Problem B
#nth equation has got at most n distinct root, therefore if we could prove the equation is held for n+1 numbers, it is always true
case=0
while True:
    case+=1
    s=input()
    if '.' in s:
        break
    p, d=s.split('/')
    d=int(d)
    p=p.replace('^','**')
    ch=''
    for i in range(0, len(p)-1):
        if p[i].isdigit() and p[i+1].isalpha():
            ch=ch+p[i]+'*'
        else:
            ch=ch+p[i]
    ch=ch+')'
    f=True
    for i in range(1, 102):
        n=i
        exec('ans='+ch)
        if ans%d:
            f=False
            print('Case %d: Not always an integer' % case)
            break
    if f:
        print('Case %d: Always an integer' % case)
