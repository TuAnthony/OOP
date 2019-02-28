This file contains a compact binary representation that supports representations of both jokers and standard cards

I changed the way the deck is created by creating a void function creatdeck that will create binary numbers with
54 strings to handle the rank and suit and determine if it is a joker.

Added the string library for makeBinary and createbinary strings to work. Make binary, performs calculations
in order to determine the binary number. The createbinary is used to display the binary values that are created
from makeBinary function. The createDecInt function creates the decimal integer by doing calculations on the
binary. 