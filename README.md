# pathfinder
In this project, a file named “output.txt” will be produced by reading the information in the
“input.txt” file located in the same directory as the application. The application will not receive any
information from the console interface. After it is opened, it will read the “input.txt” file in the
folder where it is located and write the result to “output.txt”. 
The input file has to write in the format below.
A1, A2, B1, B2, B3(Points that path will pass over)
Links: (Existing directional links)
A1-> A2
A1-> B1
A2-> B1
B1-> B2
B1-> B3
B1-> A1
B3-> A1
Paths:(Paths that will be search for)
AAB
ABB
ABBAAB
AAAB

The output text will be in the format below
AAB [YES]
ABB [YES]
ABBAAB [YES]
AAAB [NO]
