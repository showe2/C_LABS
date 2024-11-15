#include <stdio.h>
#include <math.h>

int main(void) {
    int n, m, i, j, D, U, midIndex, nullCouter = 0;
    int foundValue;
    double x;

    printf("Enter the size of your matrix (2 values separated by space): <rows columns>\n");
    scanf("%d %d", &m, &n);

    if ((m<7 || m>10) || (n<7 || n>10)) {
        printf("Error! The size values should be between 7 and 10.");
        return 0;
    }

    // double matrix[5][5]={{23,54,23,6,3},
    //                     {20,45,19,6,3},
    //                     {16,36,16,5,2},
    //                     {15,30,13,3,2},
    //                     {10,14,9,1,1}};
    
    double matrix[m][n];
    int values[m];

    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            printf("Enter a value for element [%d][%d]: ", j, i);
            scanf("%lf", &matrix[j][i]);
            if (j>0 && matrix[j][i]>matrix[j-1][i]){
                printf("Error! The values should be sorted in descending order.\n");
                printf("Element's [%d][%d] value was changed to %.2lf!\n", j, i, matrix[j-1][i]);
                matrix[j][i]=matrix[j-1][i];
            }
        }
    }

    printf("Input matrix:\n");
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Enter the required value: ");
    scanf("%lf", &x);
    i=0;

    for (i=0; i<m; i++) {
        printf("----I: %d----\n", i);
        U = 0;
        D = m-1;
        foundValue = 0;
        while (U<D && foundValue==0) {
            if (matrix[U][i]==x) {
                foundValue = 1;
                values[i] = U;
                printf("found!\n");
            }
            else {
                midIndex = floor((U+D)/2);
                printf("U[%d]: %lf\n", U, matrix[U][i]);
                printf("D[%d]: %lf\n", D, matrix[D][i]);
                printf("MID[%d]: %lf\n", midIndex, matrix[midIndex][i]);
                if (matrix[midIndex][i]>x) {
                    U = midIndex+1;
                }
                else D = midIndex;
            }
        }
        if (foundValue==0) {
            if (matrix[D][i]==x){
                values[i] = D;
                printf("found!\n");
            }
            else values[i] = m;
        }  
    }

    printf("END\n");

    printf("The elements were found in the following positions:\n");
    for (i=0; i<m; i++){
        if (values[i]<m){
            printf("[%d][%d] ", values[i], i);
        }
        else nullCouter+=1;
    }

    if (nullCouter==m){
        printf("Error! There are no elemnts such as <%.2lf>.", x);
    }

    return 0;
}