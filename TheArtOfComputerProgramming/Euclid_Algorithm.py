# Given 2 positive integers m and n, find their greatest common divisor
# Largest positive integers that evenly divides both m and n

# Algorithm
# E0. [Ensure m >= n.] if m < n, exchange(m, n)
# E1. [Find Remainder.] Divide m by n
# E2. [Is it zero?] if r == 0, return n
# E3. [Reduce.] Set m = n, n = r and rpeate


def euclid(m, n):

    if m > 0 and n > 0:  # Ensure that both numbers are positive integers

        if m < n:  # Ensure m >= n
            m, n = n, m  # If not, swap

        r = m % n  # Find the remainder of m divided by n

        if r == 0:  # If remainder is 0 Return number
            return n
        else:
            return(euclid(n, r))  # Reduce. Update m by n and n by r


print(euclid(119, 544))
