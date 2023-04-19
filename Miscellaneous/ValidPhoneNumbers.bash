#read from file.txt and output valid phone numbers to stdout
#valid phone numbers are in the format (xxx) xxx-xxxx
#where x is a digit

grep -P '^(\(\d{3}\) |\d{3}-)\d{3}-\d{4}$' file.txt

