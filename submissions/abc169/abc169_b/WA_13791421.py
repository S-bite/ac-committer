n = int(input())
v = list(map(int, input().split()))
ans = 1
for i in range(n):
    ans *= v[i]
    if (ans > 10**18):
        print(-1)
        exit()
print(ans)
