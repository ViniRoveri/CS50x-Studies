# TODO
cardNumber = input("Card number: ")


totalSum = 0


currentIndex = 2
while currentIndex <= len(cardNumber):
   currentNum = cardNumber[currentIndex * -1]
   multipliedNum = int(currentNum) * 2
   for digit in str(multipliedNum):
      totalSum += int(digit)

   currentIndex += 2


currentIndex = 1
while currentIndex <= len(cardNumber):
   currentNum = cardNumber[currentIndex * -1]
   totalSum += int(currentNum)

   currentIndex += 2


firstDigit = int(cardNumber[0])
firstTwoDigits = int(cardNumber[0:2])


if str(totalSum)[-1] != '0':
   print('INVALID')
elif firstDigit == 4 and (len(cardNumber) is 13 or len(cardNumber) is 16):
   print('VISA')
elif (firstTwoDigits == 34 or firstTwoDigits == 37) and len(cardNumber) is 15:
   print('AMEX')
elif firstTwoDigits >= 51 and firstTwoDigits <= 55 and len(cardNumber) is 16:
   print('MASTERCARD')
else:
   print('INVALID')
