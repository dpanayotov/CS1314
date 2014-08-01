balance = 320000
annualInterestRate = 0.2
monthlyInterestRate = (annualInterestRate) / 12
epsilon = 0.01
lowerBound = balance / 12
upperBound = (balance * (1 + monthlyInterestRate)**12) / 12
ans = (upperBound + lowerBound)/2.0
newBalance = balance
while abs(0 - newBalance) >= epsilon:
    newBalance = balance
    for i in range(0, 12):
        newBalance = round(((newBalance - ans) * (1 + monthlyInterestRate)), 2)
    if newBalance >= 0:
        lowerBound = ans
    else:
        upperBound = ans
    ans = (upperBound + lowerBound)/2.0
print("Lowest Payment: " + str(round(ans, 2)))
