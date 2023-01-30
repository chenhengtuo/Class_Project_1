# Class_Project_1

Step 0: inFile <- open from argv[1]
outFile1, outFile2 <- open from argv[2], argv[3].
Step 1: S <- creates a LLStack using constructor.
Step 2: buildStack(S, inFile, outFile1) 
Step 3: close inFile
Step 4: re-open inFile 
Step 5: Q <- creates a LLQueue using constructor.
Step 6: buildQueue (inFile, outFile2) 
Step 7: close inFile

======================================================================

I. Input (use argv[1]): a text file contain a list of pair {<op, data>}, one pair per text line, 
 where op is either - or +. - means delete, + means insert and data is a character string. 
For example,
/+ Tom
/+ Adam
+ Sean
+ Michael
- Tom
- Tim
********************************
II. Outputs: There will be two output files.
********************************
1) outFile1 (use argv[2]): for stack outputs.
2) outFile2 (use argv[3]): for queue outputs. 
