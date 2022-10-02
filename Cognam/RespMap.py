# create a list of response codes
responseCodes = []
# open the file
with open('./Cognam/responseCode.txt', 'r') as f:
    # read the file
    lines = f.readlines()
    # loop through the lines
    for line in lines:
        #do not add the line if it blank
        if line.strip() == '':
            continue
        # strip the line
        line = line.strip()
        # append the line to the list
        responseCodes.append(line)

# sort the list
responseCodes.sort()

#remove duplicates
responseCodes = list(dict.fromkeys(responseCodes))

# print the list
# print(responseCodes)

# map the list to a dictionary with values between 6001 to 6999 with exception of 00000000 -> 0000
responseCodes = dict(zip(responseCodes, range(6000, 6999)))
responseCodes['00000000'] = '0000'

#print the dictionary
print(responseCodes)

# print the dictionary in a format that can be used in a Cognam script
# for key, value in responseCodes.items():
#     print(key, value)