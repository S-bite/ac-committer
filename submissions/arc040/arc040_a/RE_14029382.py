n=int(input())
r=0
b=0
for i in range(n):
  r+=input().count("R")
  b+=input().count("B")
if (r<b):
  print("AOKI")
elif (b<r):
  print("TAKAHASHI")
else:
  print("DRAW")