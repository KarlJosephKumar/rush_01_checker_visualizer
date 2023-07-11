# Rush 01 (Skyscraper puzzle) checker, visualizer

To compile the executables: make in the source folder.

For usage with the output of rush 01.
The program reads the rush from stdin.

ARG="4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"; ./rush_01 $ARG | ./Checker_rush $ARG; ./fdfexec output

This is a valid output for the checker.
4x4
Arguments are the top, bottom, left, right for the rush. Pipe that output into Checker_rush and add the arguments.
The checker will check validity of the output of the rush and produce a "output" file.
"output" file can be used for the fdf for visual representation of the solved skyscraper puzzle.

9x9 file provided will include the arguments in it which should be removed for the testing purposes. The grid is valid with the arguments.
To test the file:

ARG="2 4 4 3 3 2 2 2 1 3 2 2 4 4 2 1 3 3 6 1 2 4 3 4 2 2 3 1 4 2 2 3 2 2 3 2"; ./Checker_rush $ARG < 9x9_with_argument.txt; ./fdfexec output

Visualizer works as follows:
Click mouse scroll and up - down movement for in and out zoom.
Right click to rotate.

Feel free to change the error messages if they are too cringe :D

# Credits to the contributors
https://github.com/LuEklund

https://github.com/nascimento-jgb

https://github.com/jboucher154

https://github.com/jontssu

https://github.com/Hseppanen

https://github.com/lanximaomao
