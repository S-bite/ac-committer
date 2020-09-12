n=int(input())
is_prime=[True for i in range(n)]
is_prime[0]=is_prime[1]=False
for i in range(2,n):
  if (is_prime[i]==False):
    continue
  j=2
  while (j*i<n):
    is_prime[i*j]=False
    j+=1
print(is_prime.count(True))