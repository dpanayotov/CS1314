balance = 3329
annualInterestRate = 0.2
monthlyInterestRate = annualInterestRate / 12.0
monthlyPaymentRate = 0.04
paid = 0
for i in range(0, 12):
    minimumMonthlyPayment = monthlyPaymentRate * balance
    unpaidBalance = balance - minimumMonthlyPayment
    paid += minimumMonthlyPayment
    print "Month: " + str(i+1)
    print "Minimum monthly payment: " + str(round(minimumMonthlyPayment, 2))
    balance = unpaidBalance + (monthlyInterestRate * unpaidBalance)
    print "Remaining balance: " + str(round(balance, 2))

print "Total paid: " + str(round(paid, 2))
print "Remaining balance: " + str(round(balance, 2))
