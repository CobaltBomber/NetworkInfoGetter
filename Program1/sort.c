#include <stdio.h>

//Zach Wadhams - Program 1

void sort(unsigned char myArray[][4], int num) {
    
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) { //checks each part of the array to see if it is in ascending order
            if (myArray[i][0] > myArray[j][0] || (myArray[i][0] == myArray[j][0] && myArray[i][1] > myArray[j][1]) || 
               (myArray[i][0] == myArray[j][0] && myArray[i][1] == myArray[j][1] && myArray[i][2] > myArray[j][2]) ||
               (myArray[i][0] == myArray[j][0] && myArray[i][1] == myArray[j][1] && myArray[i][2] == myArray[j][2] && myArray[i][3] < myArray[j][3])) {
                
                unsigned char t;
                for (int k = 0; k < 4; ++k) { //if not in ascending order, swap the two and repeat until finished
                    t = myArray[i][k];
                    myArray[i][k] = myArray[j][k];
                    myArray[j][k] = t;                    

                }
            }
        }

    }
    
    return;
}
