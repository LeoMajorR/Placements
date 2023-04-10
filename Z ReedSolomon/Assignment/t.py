import sys, ast

sys.path.append('..')
from reedSolo import RSCodec

rsc = RSCodec(10)
input = 'Hello World'
# convert input to byte string
encoded = rsc.encode(input.encode())
# bytearray(b'Hello Worldi6)\xe5\xe9ba8\xa5\xc4') convert to array without decoding
dispEncoded = [x for x in encoded]
print(encoded)

decoded = rsc.decode(encoded)
# convert decoded byte string to string
print(decoded[0].decode())

s = "bytearray(b'Hello Worldi6)\xe5\xe9ba8\xa5\xc4')"
# decoded = rsc.decode(s)
# print(decoded[0].decode())