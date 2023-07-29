def getZarr(string, z):
    n = len(string)
    l, r, k = 0, 0, 0

    for i in range(1, n):
        if i > r:
            l, r = i, i
            while r < n and string[r - l] == string[r]:
                r += 1
            z[i] = r - l
            r -= 1
        else:
            k = i - l
            if z[k] < r - i + 1:
                z[i] = z[k]
            else:
                l = i
                while r < n and string[r - l] == string[r]:
                    r += 1
                z[i] = r - l
                r -= 1

    return z

def zAlgorithm(s, p, n, m):
    res = 0
    concat = p + "$" + s
    l = len(concat)
    z = [0] * l
    z = getZarr(concat, z)
    for i in range(l):
        if z[i] == m:
            res += 1
    return res