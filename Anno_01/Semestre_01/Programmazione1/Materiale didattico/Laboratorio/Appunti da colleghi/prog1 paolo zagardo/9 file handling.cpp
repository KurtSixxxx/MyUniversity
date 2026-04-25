Create a File in C
FILE *fptr;
fptr = fopen("filename.txt", "w");
r = read,w = write,a= append,rb=reading in binary mode,wb= writing in binary
mode,w+= se il file non esiste viene creato


fgets(buffer, sizeof(buffer), file) legge una riga dal file e viene memorizzato
in buffer, input the whole line from the file. char *fgets (char *str, int n, FILE *stream);
fseek(file, 0, SEEK_SET) sposta il puntatore del file all'inizio del file.
fprintf(file, "New content\n") scrive "New content\n" all'inizio del file
fclose(file) chiude il file
fscanf(FILE *stream, const char *format, …) This function is used to read input 
from a file
int fgetc(FILE *pointer) fgetc() is used to obtain input from a file single character at a time
size_t fread(void * buffer, size_t size, size_t count, FILE * stream); 
The C fread() is a standard library function used to read the given amount of data from a file stream. 
fgetw()	Reads a number from a file.
int fprintf(FILE *fptr, const char *str, ...); fprintf is used to print content in file instead of stdout console.
fprintf(fptr,"%d.%s\n", i, str);
FILE* fp;
fp = fopen("f1.txt", "w");
 // Write string to file
fputs(str, fp);
int fgetc(FILE *pointer) fgetc() is used to obtain input from a file single character at a time
fprintf()	Similar to printf(), this function use formatted string and varible arguments list to print output to the file.
fputs()	Prints the whole line in the file and a newline at the end.
fputc()	Prints a single character into the file.
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *file_pointer); The fread() function can be used to read data from a binary file in C.
int fseek(FILE *ptr, long int offset, int pos); 
pointer: It is the pointer to a FILE object that identifies the stream.
offset: It is the number of bytes to offset from the position
position: It is the position from where the offset is added. Position defines the point with respect to which the file pointer needs to be moved. It has three values:
SEEK_END: It denotes the end of the file.
SEEK_SET: It denotes starting of the file.
SEEK_CUR: It denotes the file pointer’s current position. 
fseek() and rewind() both functions are used to file positioning defined in <stdio.h> header file. 
fseek() is used to set the file position indicator to a specified offset from the specified origin.
void rewind(FILE *stream); rewind is used to move the file pointer to the beginning of the file stream,while fseek is used to move the file pointer to a specific position.
 
