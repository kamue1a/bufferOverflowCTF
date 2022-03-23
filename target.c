/**********************************************************************
This program is a simple driver to demonstrate the danger of unguarded
buffers. Given what you see, how will you print the flag?

Good luck!
- Kamuela

Note that this was compiled on Kali Linux with the following commands:
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
gcc target.c  -o target -g -fno-stack-protector -z execstack -no-pie --no-warnings
echo 1 | sudo tee /proc/sys/kernel/randomize_va_space

*///******************************************************************

#include <stdio.h>

const unsigned int BUFF_SIZE = 10;


void PrintFlag(){
    // Read the flag and print it.
    char ch = '\n';
    FILE *fptr = fopen("flag.txt", "r");
    while(ch != EOF){
        putchar(ch);
        ch = fgetc(fptr);
    }

    fclose(fptr);
}


void GetKey(){
    char key[BUFF_SIZE];
    printf("\nEnter the key:\n");
    gets(key);
}


int main(){

    GetKey();

    //PrintFlag();

    return 0;
}

