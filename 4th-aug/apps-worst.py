import sys
from random import randrange

try:
  print('100 10000000', flush=True)
  for _ in range(0, 100):
    print(randrange(10000000))
  for _ in range(0, 100):
    print(randrange(100))

except (BrokenPipeError, IOError):
  pass
