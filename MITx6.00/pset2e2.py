balance = 3329
annualInterestRate = 0.2
monthlyInterestRate = annualInterestRate / 12.0
minimumMonthlyPayment = 10
newBalance = balance
while(newBalance >= 0):
    newBalance = balance
    for i in range(0,12):
        monthlyUnpaidBalance = newBalance - minimumMonthlyPayment
        newBalance = monthlyUnpaidBalance + (monthlyInterestRate * monthlyUnpaidBalance)
    if newBalance > 0:
        minimumMonthlyPayment+=10


print "Lowest Payment: " + str(minimumMonthlyPayment)
