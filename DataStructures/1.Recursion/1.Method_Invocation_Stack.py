def foo(n):

    if n < 1:
        return
    else:
        foo(n - 1)

    print(f"foo({n}) is complete")


if __name__ == "__main__":
    foo(3)
