while True:
    cString = input("How much change? ")
    change = float(cString)
    if change >= 0:
        break

count = 0
balance = change*100
quarter = 25
dime = 10
nickel = 05
penny = 01

while True:
    # Quarter
    if balance - quarter >= 0:
        count += 1
        balance = balance-quarter
    
    # Dime
    elif balance - dime >= 0:
        count += 1
        balance = balance-dime
    
    # Nickel
    elif balance - nickel >= 0:
        count += 1
        balance = balance-nickel
    
    # Penny
    elif balance - penny >= 0:
        count += 1
        balance = balance-penny
    
    if balance <= 0:
        break
print count
