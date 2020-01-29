def fibonacci(n):

    if n < 1:
        print("Can't Calculate fibonacci for negative numbers")
    elif n == 1 or n == 2:
        return n - 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


if __name__ == "__main__":
    print(fibonacci(40))
