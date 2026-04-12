"""
Project 2A - Python Factor Counting
"""

for i in range(2, 1000):
    the_number = i
    num_factors = 0
    for j in range(2, i-1):
        if (the_number % j == 0):
            num_factors +=1
            while (the_number % j == 0):
                the_number = the_number / j
    if num_factors == 3:
        print(f"{i} has three factors")