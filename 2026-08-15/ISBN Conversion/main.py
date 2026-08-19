def check(s, n, hyphens):
    if len(hyphens) > 3:
        return False

    if hyphens and 0 == hyphens[0]:
        return False

    if hyphens and n - 1 == hyphens[-1]:
        return False

    if len(hyphens) == 3 and n - 2 != hyphens[-1]:
        return False

    for h in hyphens:
        if h + 1 in hyphens:
            return False
    return True


n = int(input())
strings_orig = []
strings = []
for i in range(n):
    s = input()
    strings_orig.append(s)
    tmp = (
        [(10 if x == "X" else int(x)) for x in s if x != "-"],
        [i for i, x in enumerate(s) if x == "-"],
    )
    strings.append(tmp)

for j, t in enumerate(strings):
    s, hyphens = t

    if not check(s, len(strings_orig[j]), hyphens):
        print("invalid")
        continue
    if len(strings_orig[j]) - len(hyphens) != 10:
        print("invalid")
        continue
    checksum = 0
    for i in range(10):
        checksum += (10 - i) * s[i]
    if checksum % 11 != 0:
        print("invalid")
        continue

    checksum_2 = 9 + 3 * 7 + 8
    # print(f"CHECKSUM: {checksum_2}")

    for i in range(len(s) - 1):
        # print(f"CHECKSUM: {checksum_2} + ")

        if i % 2 != 0:
            checksum_2 += s[i]
        else:
            checksum_2 += 3 * s[i]

    # print(f"{s[i]} = {checksum_2}, {i} ")

    print("978-" + strings_orig[j][:-1] + f"{10 - (checksum_2 % 10)}")
