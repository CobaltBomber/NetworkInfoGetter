#include <stdio.h>
#include <stdlib.h>

//Zach Wadhams - Program 1

void assign(unsigned char *myArray, int num) { //brings in the array and how many ip addresses it will contain
    
    int i = 0; //below assigns each 1/4 of the ip address to each part of the array, once it finishes, it move to the next ip
    while(scanf("%hhu.%hhu.%hhu.%hhu", (myArray + 4*i + 0), (myArray + 4*i +1), (myArray + 4*i + 2), myArray + 4*i + 3) == 4) { 
        i++;
    }
    
    if (i != num) { //gives an error if the wrong number of addresses is provided
        perror("ERROR: wrong number of addresses \n");
        exit(1);        
    }   

    return;
}
