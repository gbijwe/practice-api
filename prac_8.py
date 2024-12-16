# Operations on fuzzy set
def union(A, B):
    Y = dict()
    for A_key, B_key in zip(A, B):
        A_val = A[A_key]
        B_val = B[B_key]

        if A_val > B_val: 
            Y[A_key] = A_val
        else: 
            Y[B_key] = B_val
    
    print("\nFuzzy set union is: ", Y)

def intersection(A, B):
    Y = dict()
    for A_key, B_key in zip(A, B):
        A_val = A[A_key]
        B_val = B[B_key]

        if A_val < B_val:
            Y[A_key] = A_val
        else:
            Y[B_key] = B_val
    
    print("\nFuzzy set intersection is: ", Y)

def compliment(A):
    Y = dict()
    for A_key in A: 
        Y[A_key] = 1 - A[A_key]
    
    print(f"\nCompliment of fuzzy set {A} is: \n", Y)

def difference(A, B):
    Y = dict()
    for A_key, B_key in zip(A, B):
        A_value = A[A_key]
        B_value = B[B_key]
        B_value = 1 - B_value
    
        if A_value < B_value:
            Y[A_key] = A_value
        else:
            Y[B_key] = B_value
            
    print('\nFuzzy Set Difference is :', Y)

def sum(A, B):
    Y = dict()
    # sum =  a + b - a*b
    for A_key, B_key in zip(A, B):
        A_val = A[A_key]
        B_val = B[B_key]
        Y[A_key] = A_val + B_val - A_val * B_val
    
    print("\nSum of sets is: ", Y)

def bounded_sum(A, B):
    Y = dict()
    for A_key, B_key in zip(A, B):
        A_val = A[A_key]
        B_val = B[B_key]
        A_val = A_val + B_val
        if A_val < 1: 
            Y[A_key] = A_val
        else: 
            Y[A_key] = 1
    
    print("\nBounded sum of sets is: ", Y)

def main(): 
    set1 = {"a": 0.2, "b": 0.3, "c": 0.6, "d": 0.6}
    set2 = {"a": 0.9, "b": 0.9, "c": 0.4, "d": 0.5}

    print("First fuzzy set: ", set1)
    print("Second fuzzy set: ", set2)
    
    union(set1, set2)
    intersection(set1, set2)
    compliment(set1)
    difference(set1, set2)
    sum(set1, set2)
    bounded_sum(set1, set2)

if __name__ == "__main__":
    main()