#import sys
#from random import randrange
#
#try:
#  output = '300000 300000'
#  for _ in range(1, 300001):
#    output += ' ' + str(1000000000 - _)
#  for _ in range(0, 300000):
#    output += ' ' + str(999700000 + _)
#
#  print(output, flush=True)
#except (BrokenPipeError, IOError):
#  pass

import sys
from random import randrange

try:
  print('300000 300000', flush=True)
  for _ in range(1, 300001):
    print(1000000000 - _)
  for _ in range(0, 300000):
    print(999700000 + _)

except (BrokenPipeError, IOError):
  pass

