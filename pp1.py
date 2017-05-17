"""
Create a program that asks the user to enter their name
and their age. Print out a message addressed to them that
tells them the year that they will turn 100 years old.

Extras:
1. Add on to the previous program by asking the user for
another number and printing out that many copies of the
previous message.

2. Print out that many copies of the previous message on
separate lines.
"""

from datetime import datetime
now = datetime
name = raw_input("Enter your name: ")
age = raw_input("Enter your age: ")

yearsUntil100 = 100 - int(age)

currentYear = 2017
print currentYear + yearsUntil100
