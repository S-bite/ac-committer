n,m=map(int,input().split())
print(max([input().count("1") for i in range(n)]))