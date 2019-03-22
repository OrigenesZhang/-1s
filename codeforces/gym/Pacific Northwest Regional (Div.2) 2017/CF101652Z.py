def check(n):
    n = str(n)
    if '0' in n:
        return False
    return True


n = int(input())
n += 1
while not check(n):
    n += 1
print(n)
