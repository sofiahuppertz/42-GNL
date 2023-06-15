# Get-Next-Line
Goal is to be able to read a file line by line by re calling this function.  The difficulty is that we have a determined (set by a macro BUFFER_SIZE) count size of bytes we read with the function read(). 
1. If end of file is set to true, return NULL
2. Check the buffer from previous call
    1. If it has a new line, make flag to go to step 4.
    2. Add to lines list and initialize the buffer. 
3. Read BUFFER_SIZE bytes from file descriptor and store them to Buffer.
    1. If we find a new line:  go to step 4.Check for the temporary buffers and the buffer before new line and count the number of bytes to allocate for the line to return. Allocate memory for the newline. Copy into new line temporary buffers and static buffer until new line. Free temporary buffers, Update the buffer. Return the new line.
    2. If we don’t find a new line, add the buffer to lines list by making a new node. Go back to step 3. 
    3. If read return NULL → set end of file flag, g to step 4.
4. Check for the temporary buffers and the buffer before new line and count the number of bytes to allocate for the line to return.
5. Copy into new line the temporary buffers and static buffer until new line.
6. Free temporary buffers.
7. Return the new line.

You will need a file descriptor, a BUFFER_SIZE macro, a char pointer for the buffer to store the read bytes, a char pointer for the static buffer, an integer to keep track of the number of bytes read, an integer to keep track of the position in the buffer, n integer to keep track of the endOfline and an integer to keep track of the end of the file.

MY CODE IS TIMEOUT IN TESTS!!!!
