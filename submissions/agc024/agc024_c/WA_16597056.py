n=int(input())
l=[int(input()) for _ in range(n)]
ans=0
if l[0]!=0:
  print(-1)
  exit()
for i in range(n-1):
  if (l[i]+1==l[i+1] or l[i+1]==1):
    ans+=1
  elif (l[i]==l[i+1]):
    ans+=l[i+1]
  elif (l[i+1]==0):
    pass
  else:
    print(-1)
    exit()
print(ans)