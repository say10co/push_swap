import random
my_list = list(range(0,5)) 
random.shuffle(my_list)
for i in my_list:
    print(i, end=' ')

