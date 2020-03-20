'''
Binary Indexed Tree also called Fenwick Tree provides a way to represent an array of numbers in an
array, allowing prefix sums to be calculated efficiently. For example, an array is [2, 3, -1, 0, 6] 
the length 3 prefix [2, 3, -1] with sum 2 + 3 + -1 = 4). Calculating prefix sums efficiently is 
useful in various scenarios. Let's start with a simple problem.

We are given an array a[], and we want to be able to perform two types of operations on it.

Change the value stored at an index i. (This is called a point update operation)
Find the sum of a prefix of length k. (This is called a range sum query)

When to use Binary Indexed Tree?

Before going for Binary Indexed tree to perform operations over range, one must confirm that the operation or the function is:

Associative. i.e f(f(a, b), c) = f(a, f(b, c)) this is true even for seg-tree

Has an inverse. eg:

addition has inverse subtraction (this example we have discussed)

Multiplication has inverse division

gcd() has no inverse, so we can’t use BIT to calculate range gcd’s

sum of matrices has inverse

product of matrices would have inverse if it is given that matrices are degenerate i.e. determinant of any matrix is not equal to 0

Space Complexity: O(N) for declaring another array of size N

Time Complexity: O(logN) for each operation(update and query as well)

'''

#Implementation

class Fenwick_Tree():
    def __init__(self, SIZE):
        self.size = SIZE
        self.ft = [0 for i in range(SIZE)]
    
    def update(self, i, value):
        while i < self.size:
            self.ft[i] += value
            i += i & (-i)
    
    def query(self, i):
        res = 0
        while i > 0:
            res += self.ft[i]
            i -= i & (-i)
        return res
if __name__ == "__main__":
    f = Fenwick_Tree(10)
    f.update(1, 20)
    f.update(4, 4)
    print(f.query(1))
    print(f.query(3))
    print(f.query(4))
    print(f.ft)
    f.update(2, -5)
    print(f.query(1))
    print(f.query(3))
    print(f.ft)