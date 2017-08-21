def gcd(x,y):
    a=max(x,y)
    b=min(x,y)
    return b if a%b==0 else gcd(b,a%b)
def lcm(x,y):
    return x*y//gcd(x,y)

N=int(input())
ans=1
for _ in range(N):
    ans=lcm(ans,int(input()))
print (ans)