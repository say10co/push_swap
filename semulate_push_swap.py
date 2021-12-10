def check_stack(stack, i):
    try:
        stack[i]
        return (1)
    except:
        return (0)

def sa():
    global stack_a
    if (check_stack(stack_a, 0) and check_stack(stack_a, 1)):
        stack_a[0], stack_a[1] = stack_a[1], stack_a[0]

def sb():
    global stack_b
    if (check_stack(stack_b, 0) and check_stack(stack_b, 0)):
        stack_b[0], stack_b[1] = stack_b[1], stack_b[0]

def pa(): 
    global stack_a
    global stack_b
    try:
        stack_a.insert(0, stack_b[0])
        stack_b = stack_b[1:]
    except:
        return
def pb(): 
    global stack_b
    global stack_a
    try:
        stack_b.insert(0, stack_a[0])
        stack_a = stack_a[1:]
    except:
        return
def ra():
    global stack_a
    t = stack_a[0]
    stack_a = stack_a[1:]
    stack_a.append(t)

def rb():
    global stack_b
    t = stack_b[0]
    stack_b = stack_b[1:]
    stack_b.append(t)

def rra():
    global stack_a
    t = stack_a[-1]
    stack_a.insert(0, t)
    stack_a = stack_a[:-1]

def rrb():
    global stack_b
    t = stack_b[-1]
    stack_b.insert(0, t)
    stack_b = stack_b[:-1]

def ss():
    sa()
    sb()

def rr():
    ra()
    rb()

def rrr():
    rra()
    rrb()

def print_staks(len_stack):
    i = 0
    while (i < len_stack):
        spc1 = "_"
        spc2 = "_"
        if (check_stack(stack_a, i)): 
            spc1 = stack_a[i]
        if (check_stack(stack_b, i)):   
            spc2 = stack_b[i]  
        print (spc1, " ", spc2)
        i += 1
    print("_   _")
    print("a   b")

def get_spot_values():
    global values_spots
    global stack_a
    spot = 0
    for value in stack_a:
        values_spots.append((value, spot))
        spot += 1
    #values_spots.sort()

def ingnore():
    i = 0
    while(True):
        op = input("Enter operation : ").split()
        if op[0] == "break":
            break
        for oper in op:
            functions[oper]()
   
        print_staks(max(len(stack_a), len(stack_b)))
        i += 1
functions = {'ss':ss, 'sa':sa, 'sb':sb, 'pa':pa, 'pb':pb, 'rr':rr,
        'rra':rra, 'rrb':rrb, 'rra':rra, 'rrb':rrb, 'rrr': rrr, 'ra':ra, 'rb':rb}

stack_a = list(map(int , input("Enter stack : ").split()))
len_stack = len(stack_a)
stack_b = []
values_spots = []
print_staks(len_stack)
get_spot_values()

ingnore();
"""
for k in range(len_stack):
    print(values_spots)
    mid = len(values_spots) // 2
    if values_spots[0][1] <= mid:
        for i in range(values_spots[0][1]):
            ra()
            print("ra ", end="")
    else:
        for j in range(values_spots[0][1] + 2 - (len(stack_a))) :
            rra()
            print("rra ", end="")
    print()
    pb()
    print_staks(max(len(stack_a), len(stack_b)))
    values_spots.clear()
    get_spot_values()
"""
