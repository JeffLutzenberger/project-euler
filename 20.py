
def fact(n):
    ans = 1
    for i in range(1, n):
        ans *= i
    return ans

ans = fact(100)

sum_digits = 0
for i in str(ans):
    sum_digits += int(i)

print(sum_digits)
