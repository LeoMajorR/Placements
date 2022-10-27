def sortOnFrequency(input):
    n = int(input)
    # initialise arr
    arr = []
    for i in range(1, len(input)):
        arr.append(int(input()))
    # initialise freq
    freq = {}
    for i in range(0, n):
        if arr[i] in freq:
            freq[arr[i]] += 1
        else:
            freq[arr[i]] = 1
    # sort freq
    freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)
    ans = ""
    for i in range(0, len(freq)):
        ans += str(freq[i][0]) + " "
    return ans
