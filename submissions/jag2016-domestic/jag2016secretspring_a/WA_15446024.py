n=int(input())
cur=0
for i in range(n):
  if (input()=="A"):
    n+=1
  else:
    n-=1
  if (n<0):
    print("NO")
    exit()
if (n==0):
  print("YES")
else:
  print("NO")