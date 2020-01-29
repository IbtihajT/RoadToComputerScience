HIGHEST = -999


def biggest_Number(li, n):

    if n == -1:
        return HIGHEST
    else:
        if li[n] > HIGHEST:
            HIGHEST = li[n]
            print(HIGHEST)

    return biggest_Number(li, n-1)


li = [5, 18, 3, 54, 26, 55, 41, 19, 1, 10]
print(biggest_Number(li, len(li)-1))
