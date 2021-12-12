# Python3 code to count pairs whose
# sum is divisible by 'K'

# Function to count pairs whose
# sum is divisible by 'K'
def countKdivPairs(A, n, K):

    # Create a frequency array to count
    # occurrences of all remainders when
    # divided by K
    freq = [0] * K
    
    # Count occurrences of all remainders
    for i in range(n):
        freq[A[i] % K] += 1
    print(freq)

    # If both pairs are divisible by 'K'
    sum = freq[0] * (freq[0] - 1) / 2
    print(sum)
    # count for all i and (k-i)
    # freq pairs
    i = 1
    while(i <= K//2 and i != (K - i)):
        sum += freq[i] * freq[K-i]
        i += 1
    print(sum)

    # If K is even
    if(K % 2 == 0):
        sum += (freq[K//2] * (freq[K//2]-1)/2) 
    print(sum)
    print(K//2)

    return int(sum)


# Driver code
A = [2, 2, 1, 7, 5, 3,3]
n = len(A)
K = 4
print(countKdivPairs(A, n, K))
