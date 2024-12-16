# Implementing the Water Jug Problem:

# Check Solvability of the Water Jug Problem
    # Condition -
    # Diophantine equation of the form mx + ny = d
    # solvable if and only if gcd(m, n) divides d
        # where m and n are the capacities of the jugs and d is the amount of water to be measured

def gcd(a, b):
    if b ==0:
        return a
    else:
        return gcd(b, (a % b))

def jugFill(fromJugCapacity, toJugCapacity, key):
    # Approach:
        # Fill the m litre jug and empty it into n liter jug.
        # Whenever the m liter jug becomes empty fill it.
        # Whenever the n liter jug becomes full empty it.
        # Repeat steps 1,2,3 till either n liter jug or the m liter jug contains d litres of water.
    fromJug = fromJugCapacity
    toJug = 0

    steps = 1
    print("step: ", steps, "\t", fromJug, "\t", toJug)

    while (fromJug != key or toJug != key):

        amountPourable = min(fromJug, toJugCapacity-toJug)

        toJug = toJug + amountPourable
        fromJug = fromJug - amountPourable # empties fromJug, since it was initially at full capacity

        steps += 1
        print("steps: ", steps, "\t", fromJug, "\t", toJug)
        if (fromJug == key or toJug == key):
            break

        if (fromJug == 0):
            fromJug = fromJugCapacity
            steps += 1
            print("steps: ", steps, "\t", fromJug, "\t", toJug)


        if (toJug == toJugCapacity):
            toJug = 0
            steps += 1
            print("steps: ", steps, "\t", fromJug, "\t", toJug)

        

    return steps


def checkSolvability(n, m, d):
    if (m > n):
        temp = n
        n = m
        m = temp

    # check the solvability of Diaphontine equation
    if (d % gcd(n,m) != 0):
        return -1

    return min(jugFill(n,m,d), jugFill(m,n,d))

def main():
    jug_1 = int(input("Please enter capacity of first jug: "))
    jug_2 = int(input("Please enter capacity of second jug: "))
    key = int(input("Please enter the amount of water to be measured: "))

    print("Checking solvability of the water jug problem...")
    print("\t", "Jug 1", "\t", "Jug")
    solvable = checkSolvability(jug_1, jug_2, key)

    if solvable == -1:
        print("The water jug problem is not solvable.")
    else:
        print("The water jug problem is solvable in ", solvable, " steps.")


if __name__ == '__main__':
    main()
