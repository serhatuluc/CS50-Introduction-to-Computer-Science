# TODO

# User is forced to give number between 1 and 8
while True:
    n = input("Width: ")
    if n.isnumeric():
        if int(n) >= 1 and int(n) <= 8:
            break

n = int(n)
m = n

for i in range(n):

    # m is decremented so that printing space is done decrementally
    m = m - 1
    for j in range(m):
        print(" ", end="")

    # Third loop is used to print hash at the end of what is printed by second loop
    for k in range(n - m):
        print("#", end="")

    # This new line take the curser to next line
    print()
