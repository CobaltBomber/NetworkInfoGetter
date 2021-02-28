#include <stdio.h>

FILE *printFile;

void print(unsigned char myArray[][4], int num) {

    printFile = fopen("output.txt", "a");
    //creates the data to store calculations
    int anet = 0, bnet = 0, cnet = 0;
    int ahost = 1, bhost = 1, chost = 1;
    int acount = 1, bcount = 1, ccount = 1;
    int atemp, btemp, ctemp;
    

    for (int i = 0; i < num; i++) { //gets number of networks in each class
        
        if (myArray[i][0] < 128) { //handles A type
            
            if (myArray[i][0] == myArray[i + 1][0]) {

                acount++;
            
                if (acount > ahost) {
                    ahost++;
                    atemp = i + 1;
                }

            }

            else if (myArray[i][0] != myArray[i + 1][0]) {
                anet++;
                acount = 1;
            }

        }

        else if (myArray[i][0] < 192) { //handles B type
            
            if (myArray[i][0] == myArray[i + 1][0]) {
            
                if (myArray[i][0] == myArray[i + 1][1]) {
                    bcount++;

                    if (bcount > bhost) {
                        bhost = bcount;
                        btemp = i + 1;
                    }
                }

                else if (myArray[i][1] != myArray[i + 1][1]) {
                    bnet++;
                    bcount = 1;
                }
            }

            else if (myArray[i][0] != myArray[i + 1][0]) {
                bnet++;
            }
        }
        
        else if (myArray[i][0] < 224) { //handles C type
            
            if (myArray[i][0] == myArray[i + 1][0]) {
                
                if (myArray[i][1] == myArray[i + 1][1]) {
                    
                    if (myArray[i][2] == myArray[i + 1][2]) {
                        ccount++;

                        if (ccount > chost) {
                            chost = ccount;
                            ctemp = i + 1;
                        }
                
                    }
       
                    else if (myArray[i][2] != myArray[i + 1][2]) {
                        cnet++;
                        ccount = 1;    
                    }
                    
                }
                
                else if (myArray[i][1] != myArray[i + 1][1]) {
                    cnet++;
                    ccount = 1;
                }

            }
    
            else if (myArray[i][0] != myArray[i + 1][0]) {
                cnet++;
            }

        }


    } 
    //prints out each class and it's info
    fprintf(printFile, "Class A has %d networks \n", anet);
    fprintf(printFile, "Largest A network is %d with %d hosts \n", myArray[atemp][0], ccount); 
    fprintf(printFile, "Class B has %d networks \n", bnet);
    fprintf(printFile, "Largest B network is %d.%d with %d hosts \n", myArray[btemp][0], myArray[btemp][1], bcount);
    fprintf(printFile, "Class C has %d networks \n", cnet);
    fprintf(printFile, "Largest C network is %d.%d.%d with %d hosts \n", myArray[ctemp][0], myArray[ctemp][1], myArray[ctemp][2], ccount);
    fprintf(printFile, "\n");
    fclose(printFile);
    //:)
    return;
}
