l=[]
for i in "123456789":
  for j in range(1,100):
    l.append(int(i*j))
l.sort()
print(l[int(input())-1])