def judge_2(val):
    cur = 1
    while cur < val:
        cur *= 2
    if cur == val:
        return True
    else:
        return False


def num1(val, n):
    l = 1
    r = int(1e18) + 1
    while l < r:
        mid = l + (r - l) // 2
        cur = 1
        for i in range(val):
            if cur > n:
                break
            cur = cur * mid

        if cur > n:
            r = mid
        elif cur < n:
            l = mid + 1
        else:
            return mid
    return -1


def num2(val1, val2, n):
    l = 1
    r = int(1e18) + 1
    while l < r:
        mid = l + (r - l) // 2
        cur = 1
        for i in range(val1):
            if cur > n:
                break
            cur *= mid
        for i in range(val2):
            if cur > n:
                break
            cur *= (mid + 1)
        if cur > n:
            r = mid
        elif cur < n:
            l = mid + 1
        else:
            return mid
    return -1


with open("little.in", "r") as f:
    n = int(f.read())

with open("little.out", "w") as f:
    ans = []

    if judge_2(n):
        print(-1, file=f)
    else:
        for i in range(1, 68):
            # print(i)
            ret = num1(i, n)
            if ret > -1:
                ans.append((ret, i))
        for i in range(1, 68):
            for j in range(1, 68):
                # print(i, j)
                ret = num2(i, j, n)
                if ret > -1:
                    ans.append((ret, i, j))
        print(len(ans), file=f)
        for it in ans:
            if len(it) == 2:
                print(it[1], end='', file=f)
                for i in range(it[1]):
                    print(' ', it[0], end='', sep='', file=f)
                print(file=f)
            else:
                print(it[1] + it[2], end='', file=f)
                for i in range(it[1]):
                    print(' ', it[0], end='', sep='', file=f)
                for i in range(it[2]):
                    print(' ', it[0] + 1, end='', sep='', file=f)
                print(file=f)


[close]
