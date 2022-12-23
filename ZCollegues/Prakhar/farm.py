# ways to reach from(1,1) to (1000000,1000000) in a grid
# movements allowed :(r+1,c+2) or (r+2,c+1)
#no oof ways from (1,1) to (r,c) down moes + right moves
# 1 down move + 2 right moves or 2 down moves + 1 right move
# r+
# return ans modulo 10^9+7
def noOfWays(r, c):
    if r == 1 and c == 1:
        return 1
    if r == 0 or c == 0:
        return 0
    return (noOfWays(r - 1, c - 2) + noOfWays(r - 2, c - 1)) % (10**9 + 7)


print(noOfWays(4, 4))
print(noOfWays(5, 5))
