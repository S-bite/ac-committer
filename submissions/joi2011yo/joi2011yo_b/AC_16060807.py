q=input()
n=int(input())
ans=0
for i in range(n):
  s=input()
  if q in s*2:
    ans+=1
print(ans)