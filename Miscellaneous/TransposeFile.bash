# read from file.txt and rint its transposed content to stdout.

grep -P '^\d{1,3}$' file.txt | paste -s -d ' ' - | tr -d ' '