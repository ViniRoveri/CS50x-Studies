# TODO
height = ''
while not height.isdigit() or int(height) < 1 or int(height) > 8:
   height = input('Height: ')

height = int(height)
for i in range(height):
   print(' ' * (height - i - 1), end='')
   print('#' * (i + 1), end='')
   print('  ', end='')
   print('#' * (i + 1))
