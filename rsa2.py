#!/usr/bin/python3
import sys

def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def factorize(n):
    if n == 0:
        print('0 has no prime factors.')
        return
    if n == 1:
        print('1 has no prime factors.')
        return

    prime_factors = []
    while n % 2 == 0:
        prime_factors.append(2)
        n //= 2
        if len(prime_factors) == 2:
            break

    i = 3
    while i <= int(n**0.5) and len(prime_factors) < 2:
        while n % i == 0:
            prime_factors.append(i)
            n //= i
            if len(prime_factors) == 2:
                break
        i += 2

    if n > 2:
        prime_factors.append(n)

    if len(prime_factors) == 2:
        p, q = prime_factors
        print(f'{n} = {p} * {q}')
    else:
        print(f'{n} does not have two distinct prime factors.')

if len(sys.argv) != 2:
    print("Usage: factors <file>")
    sys.exit(1)

filename = sys.argv[1]
try:
    with open(filename, 'r') as file:
        n = int(file.read().strip())
except FileNotFoundError:
    print(f"File '{filename}' not found.")
    sys.exit(1)
except ValueError:
    print("Invalid file format. Please provide a file containing a single integer.")
    sys.exit(1)

factorize(n)
