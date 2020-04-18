import re
p=re.compile(".*okyo.*ech.*")
n=int(input())
for i in range(n):
  print("YNeos"[not p.match(input())::2])