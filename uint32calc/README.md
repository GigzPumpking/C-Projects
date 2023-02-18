# Unsigned Integer Simple Calculator

## Description:
A simple add/sub/mul/div calculator for unsigned integers. No decimals: displays remainder if any.

Enter two integers as arguments and clarify which operations you would like to perform on said integers.

Displays the results of all operations on the same numbers.

## Included Files:
        sorting.c

        Makefile
            - Used to build the calculator.c executable, clang-format relevant files, and clean the directory.
	README.md
	    - Provides program description, included files, how to build and run the program, and how to clean the directory.

## Build:
Run '$ make' on the command line within the uint32calc directory to create the executable calculator file along with the relevant object files.

## Clean:
Run ‘$ make clean’ on the command line within the uint32calc directory to remove the executable calculator file and any .o file in the directory.

## Run:
Run '$ ./sorting' along with any of the listed options:

        -H             | - Display program help and usage. If no operation was clarified, help will be displayed.

        -a             | - Adds num1 and num2.

        -s             | - Subtracts num1 and num2.

        -m             | - Multiplies num1 and num2.

        -d             | - Divides num1 and num2, displays remainder.

        -i num1        | - Sets num1 to user argument (Defaults to 0).

        -j num2        | - Sets num2 to user argument (Defaults to 0).
