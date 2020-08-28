import sys
from random import randrange

try:
  output = '300000 300000'
  for _ in range(300000):
    output += ' ' + str(1000000000 - _)
  for _ in range(300000):
    output += ' ' + str(1000000000 - _)

  print(output, flush=True)
except (BrokenPipeError, IOError):
  pass

#
#sys.stderr.close()

#print ('''
#7 3
#5 6 4 3 6 2 3
#3 2 5
#''')
#from random import randrange
#output = '300000 300000'
#for _ in range(3000000):
#  output += ' ' + str(randrange(1000000000))
#for _ in range(3000000):
#  output += ' ' + str(randrange(1000000000))
#print(output)
