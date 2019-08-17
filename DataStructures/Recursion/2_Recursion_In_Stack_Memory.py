def foo(number):

    if (number < 1):
        return
    else:
        foo(number - 1)

    print(f"Hello, World {number}")


if __name__ == "__main__":
    foo(5)
