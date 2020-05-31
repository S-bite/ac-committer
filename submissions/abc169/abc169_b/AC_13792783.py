n = int(input())
v = list(map(int, input().split()))
if 0 in v:
    print(0)
    exit()
ans = 1
for i in range(n):
    ans *= v[i]
    if (ans > 10**18):
        print(-1)
        exit()
print(ans)
