def fibonacci(number):

    if number < 1:
        print("Fibonacci Can't be of negative number.")

    elif number == 1 or number == 2:
        return number - 1

    else:
        return fibonacci(number-1) + fibonacci(number-2)


if __name__ == "__main__":
    print(fibonacci(4))
