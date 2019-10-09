# Test file for Lab2_introToAVR


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 0x00 => PORTC: 0x40"
# Set inputs
setPINA 0x00
# Continue for several ticks
continue 5
# Set expect values
expectPORTC 0x40
# Check pass/fail
checkResult

# Add tests below

# Example test:
test "PINA: 0x01 => PORTC: 0x60"
# Set inputs
setPINA 0x01
# Continue for several ticks
continue 5
# Set expect values
expectPORTC 0x60
# Check pass/fail
checkResult


# Example test:
test "PINA: 0x03 => PORTC: 0x70"
# Set inputs
setPINA 0x03
# Continue for several ticks
continue 5
# Set expect values
expectPORTC 0x70
# Check pass/fail
checkResult


# Example test:
test "PINA: 0x05 => PORTC: 0x38"
# Set inputs
setPINA 0x05
# Continue for several ticks
continue 5
# Set expect values
expectPORTC 0x38
# Check pass/fail
checkResult


# Example test:
test "PINA: 0x07 => PORTC: 0x3C"
# Set inputs
setPINA 0x07
# Continue for several ticks
continue 5
# Set expect values
expectPORTC 0x3C
# Check pass/fail
checkResult


# Example test:
test "PINA: 0x0A => PORTC: 0x3E"
# Set inputs
setPINA 0x0A
# Continue for several ticks
continue 5
# Set expect values
expectPORTC 0x3E
# Check pass/fail
checkResult


# Example test:
test "PINA: 0x0F => PORTC: 0x3F"
# Set inputs
setPINA 0x0F
# Continue for several ticks
continue 5
# Set expect values
expectPORTC 0x3F
# Check pass/fail
checkResult




# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
