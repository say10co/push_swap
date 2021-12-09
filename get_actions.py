# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_actions.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriouic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 09:45:01 by adriouic          #+#    #+#              #
#    Updated: 2021/12/09 11:31:48 by adriouic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from semulate_push_swap import *

#stack_a = list(map(int, input("Enter Stack ; ").split()))
#stack_b = []

values_spots = []

def get_spot_values(): 
    global values_spots
    global stack_a
    spot = 0
    for value in stack_a:
        values_spots.append((value, spot))
        spot += 1
    values_spots.sort()

print_staks(len_stack)
get_spot_values()
mid = len(values_spots) // 2

for k in range(len_stack): 
    print(values_spots)
    if values_spots[k][1] <= mid:
        for i in range(values_spots[k][1]):
            ra()
            print("ra ", end="")
    else:
        for j in range(values_spots[k][1]):
            rra()
            print("rra ", end="")
    print()
    pb()
    print_staks(max(len(stack_a), len(stack_b)))
    values_spots.clear()
    get_spot_values()
#def rrx_or_rx()
