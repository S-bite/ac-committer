x,n=map(int,input().split())
l=list(map(int,input().split()))
ans=200
for i in range(-200,200):
  if (i not in l and abs(x-i)<abs(x-ans)):
    ans=i
print(ans)