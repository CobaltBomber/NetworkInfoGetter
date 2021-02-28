#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Zach Wadhams - Program 1

void assign(unsigned char myArray[][4], int num);
void sort(unsigned char myArray[][4], int num);
void print(unsigned char myArray[][4], int num);

int main(int argc, char** argv) {
    
    //get integer from command line arguments
    
    if (argc != 2) { //prints out error if there are no arguments
        printf("ERROR: no command line arguments, for file: ");
        exit(0);
    }

    int numAddresses = atoi(argv[1]); 
        
    unsigned char data[numAddresses][4];             
    //create array by number of addresses x 4
   
    assign(data, numAddresses);
    //FUNCTION: read all addresses into array
    sort(data, numAddresses); 
    //FUNCTION: Sort array
    print(data, numAddresses);
    //FUNCTION: count and print number of networks in each class
    //for A B and C, not D OR E

    return(0);
}
