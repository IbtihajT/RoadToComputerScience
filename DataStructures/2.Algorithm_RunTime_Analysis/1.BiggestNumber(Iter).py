def biggest_Number(li):
    # -------------------------------------------------------- O(1)
    biggest_Number = li[0]
    for i in range(1, len(li)-1):  # ------------------ O(n) ------------------------- O(n)
        if li[i] > biggest_Number:  # ---- O(1) -----   O(1)
            biggest_Number = li[i]  # ---- O(1) -----
    # --------------------------------------------------------- O(1)
    return biggest_Number

    # Time Complexity = O(1) + O(n) + O(1)
    #                 = O(n)


if __name__ == "__main__":
    print(biggest_Number([5, 18, 3, 54, 26, 55, 41, 19, 1, 10]))
