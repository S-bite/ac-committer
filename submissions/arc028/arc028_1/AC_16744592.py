n,a,b=map(int,input().split())
while True:
  n-=a;
  if (n<=0):
    print('Ant')
    break;
  n-=b;
  if (n<=0):
    print('Bug')
    break;
  