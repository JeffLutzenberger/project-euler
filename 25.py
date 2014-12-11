decimals = 1000
count = 0
fib1 = 1
fib2 = 1
fib3 = 2
term = 2

while count < decimals:
    fib3 = fib1 + fib2
    fib1 = fib2
    fib2 = fib3
    term += 1
    count = len(str(fib3))

print("F_" + str(term) + ": " + str(fib3))
