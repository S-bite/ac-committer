l=[int(input()) for i in range(6)]
print(sum(l)-min(l[:4])-min(l[4:]))