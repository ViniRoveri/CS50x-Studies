def main():
   inputText = input('Text: ').lower()

   wordsInText = inputText.count(' ') + 1
   lettersPer100 = getLettersInText(inputText) * 100 / wordsInText
   sentencesPer100 = getSentencesInText(inputText) * 100 / wordsInText

   index = round(0.0588 * lettersPer100 - 0.296 * sentencesPer100 - 15.8)
   if index < 1:
      print('Before Grade 1')
   elif index > 15:
      print('Grade 16+')
   else:
      print('Grade ' + str(index))


def getLettersInText(text):
   total = 0

   for char in text:
      if char >= 'a' and char <= 'z':
         total += 1

   return total


def getSentencesInText(text):
   total = 0

   for char in text:
      if char == '.' or char == '!' or char == '?':
         total += 1

   return total


main()