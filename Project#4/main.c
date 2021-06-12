#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int subsetSum(int* set, int count, int sum) {
    if (sum == 0)
        return 1;
    if (count == 0 && sum != 0)
        return 0;

    if (set[count - 1] > sum)
        return subsetSum(set, count - 1, sum);

    return subsetSum(set, count - 1, sum) ||
           subsetSum(set, count - 1, sum - set[count - 1]);
}

    void setDifference(int* S, int countS, int* T, int countT, int** R, int* countR){

        int i, j;
        int found = 0;
        int *D = (int*)malloc(sizeof(int) * countS);
        int countD = 0;
        for (i=0; i < countS; i++){
            for (j = 0; j < countT; j++) {
                if (S[i] == T[j]) {
                    found = 1;
                }
            }
            if (found == 0){
                D[countD] = S[i];
                countD++;
            }
            else{
                found == 0;
            }
        }
        *R = D;
        *countR = countD;
    }

    int properSubset(int* s, int counts, int* T, int countT){
        {
            int i = 0;
            int j = 0;
            for (i=0; i < counts; i++)
            {
                for (j = 0; j < countT; j++)
                {
                    if (s[i] == T[j])
                        break;
                }
                if (j == countT)
                    return 0;
            }

            return (counts < countT);
        }
    }

    int main() {
        int setS[] = {3, 34, 4, 12, 5, 2};
        int setT[] = {4, 5, 34};
        int sum = 9;
        int countS = sizeof(setS) / sizeof(setS[0]);
        int countT = sizeof(setT) / sizeof(setT[0]);
        int *setD;
        int countD = 0;
        if (subsetSum(setS, countS, sum) == 1)
            printf("Found a subset with given sum.\n");
        else
            printf("No subset with given sum.\n");

        setDifference(setS, countS, setT, countT, &setD, &countD);

        if (properSubset(setT, countT, setS, countS) == 1)
            printf("Is a proper subset.\n");
        else
            printf("Is not a proper subset.\n");
        return 1;
    }

