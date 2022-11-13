import random

path = './test.in'

with open(path, 'w') as fp:
  num = 10
  for _ in range(num):
    n = random.randint(1, 1000000000000000001)
    fp.write(str(n) + '\n')

fp.close()

  
