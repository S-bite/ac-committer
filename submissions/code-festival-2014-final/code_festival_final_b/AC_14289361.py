ans=0
sgn=1
for c in input():
  ans+=sgn*int(c)
  sgn*=-1
print(ans)