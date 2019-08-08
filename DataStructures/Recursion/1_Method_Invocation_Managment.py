def Bar():
    DoWork()  # Bar() pushed to stack and control transfered to DoWork()
    print("I'm in Bar")


def DoWork():
    DoMore()  # DoWork() pushed to stack and control transfered to DoMore()
    print("I'm in DoWork")


def DoMore():
    print("I'm in DoMore")


if __name__ == "__main__":
    Bar()  # Main pushed to stack and control transfered to Bar()
    print("I'm in main")
