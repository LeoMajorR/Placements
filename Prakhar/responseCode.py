# create a list of response codes
responseCodes = []
# open the file
with open('responseCodes.txt', 'r') as f:
    # read the file
    lines = f.readlines()
    # loop through the lines
    for line in lines:
        # strip the line
        line = line.strip()
        # append the line to the list
        responseCodes.append(line)

# sort the list
responseCodes.sort()

# print the list
# print(responseCodes)

# map the list to a dictionary with values between 6001 to 6999 with exception of 00000000 -> 0000
responseCodes = dict(zip(responseCodes, range(6001, 6999)))
responseCodes['00000000'] = '0000'

# print the dictionary
print(responseCodes)