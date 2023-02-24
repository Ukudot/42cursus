import random
import sys

ran = [x for x in random.sample(range(-2147483648, 2147483648), int(sys.argv[1]))]
for x in ran:
    print(x, end = " ")
