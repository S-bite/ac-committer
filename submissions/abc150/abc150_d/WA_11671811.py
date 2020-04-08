import fractions


def lcm(x, y):
    return (x * y) // fractions.gcd(x, y)


n, m = map(int, input().split())
v = list(map(int, input().split()))
num = 0
while (v[0] % 2 != 0):
    v[0] //= 2
    num += 1
ans = v[0]
for i in range(n - 1):
    if (v[i + 1] % 2 ** num != 0 or v[i + 1] % 2 ** (num+1) == 0):
        print(0)
        exit(0)
    else:
        v[i+1] //= 2**num
        ans = lcm(ans, v[i + 1])
if (ans % 2 == 0):
    print(0)
    exit(0)

ans *= 2**num
print(m//ans)
