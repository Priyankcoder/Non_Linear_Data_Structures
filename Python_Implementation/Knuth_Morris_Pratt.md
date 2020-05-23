# Knuth Morris Pratt Algorithm.
> This algorithm is used to find the pattern in a text.It can do so in linear time complexity while brute-force method do so in cubic time comlexity. <br>
It's used as DNA matching algorithm.

## Python Implementation:

``` python
# Utility function to calculate array to store 
# largest prefix in suffix until the ith
#  index of string at index i.

def computeLPSArray(pat, M, lps):
    len = 0
    i = 1
    lps[0] = 0
    while i < M:
        if pat[len] == pat[i]:
            lps[i] = len + 1
            len += 1
            i += 1
        else:
            if len != 0:
                len = lps[len-1]
            else:
                lps[i] = 0
                i += 1

# Main Function
def KMPSearch(pat, txt):
    count = 0       #To count the total pattern found
    N = len(txt)    
    M = len(pat)
    lps = [0]*M  
    computeLPSArray(pat, M, lps) 
    i = 0
    j = 0
    while i < N:
        if txt[i] == pat[j]:
            i += 1
            j += 1
        else:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
        if j == M:
		# print(i-j) If you want to print the
		# starting position of found pattern
            count += 1    
            j = lps[j-1]
    return count
if __name__ == "__main__":
    pat = str(input())
    txt = str(input())
    print(KMPSearch(pat, txt))
```
## Time and Space Complexity.
Time complexity is O(n+m) which is equivalent to *O(n)* and space complexity is *O(n)*.



 