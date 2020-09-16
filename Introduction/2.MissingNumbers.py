n = int(input())
arr = [int(i) for i in input().split()]
sum = 0
for i in arr:
    sum+= i
print(int(n*(n+1)/2) - sum)