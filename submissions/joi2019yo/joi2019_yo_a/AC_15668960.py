a,b,c=map(int,input().split())
ans=0
num=0
while(num<c):
  ans+=1
  num+=a
  if (ans%7==0):
    num+=b
print(ans)