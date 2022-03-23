/**********************************************************************
This program is a simple driver to demonstrate the danger of unguarded
buffers. Given what you see, how will you print the flag?

Good luck!
- Kamuela

Note that this was compiled on Kali Linux with the following commands:
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
gcc target.c  -o target -g -fno-stack-protector -z execstack -no-pie --no-warnings -static -lm
echo 1 | sudo tee /proc/sys/kernel/randomize_va_space

*///******************************************************************

#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

const unsigned int BUFF_SIZE = 10;


double Arbitrary(){
    
    double a = pow(4.3, 5.8);
    double b = pow(8.2, 9.4);
    double c = pow(log(a),log(b));
    double d = pow(log(a),log(c));
    double e = pow(log(b),log(c));
    double f = pow(log(d),log(e));
    
    assert(atan2(f, .6) < FLT_MIN_EXP);
    
    a = atan2(4.3, 5.8);
    b = atan2(8.2, 9.4);
    c = pow(log(a),log(b));
    d = pow(log(a),log(c));
    e = pow(log(b),log(c));
    f = pow(log(d),log(e));
    
    assert(atan2(f, .6) < FLT_MAX_EXP);
    
    a = fmod(f - b, c);
    b = fmod(f - a, c);
    c = pow(log(a),log(b));
    d = fmod(f - c, a);
    e = fmod(f - c, b);
    f = pow(log(d),log(e));

    double g = pow(4.3, 5.8);
    double h = pow(8.2, 9.4);
    double i = pow(log(g),log(h));
    double j = pow(log(a),log(i));
    double k = pow(log(h),log(i));
    double l = pow(log(j),log(k));
    
    g = atan2(4.3, 5.8);
    h = atan2(8.2, 9.4);
    i = pow(log(g),log(h));
    j = pow(log(g),log(i));
    k = pow(log(h),log(i));
    l = pow(log(j),log(k));
    
    assert(atan2(l, .6) < FLT_MIN_EXP);
    
    g = fmod(l - h, i);
    h = fmod(l - g, i);
    i = pow(log(g),log(h));
    j = fmod(l - i, g);
    k = fmod(l - i, h);
    l = pow(log(j),log(k));
    
    int m = ceil(a);
    int n = ceil(b);
    int o = ceil(c);
    int p = ceil(d);
    int q = m*n*o/p;
    
    return sqrt(exp(f*l*q)*log(f*l*q));
}


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

