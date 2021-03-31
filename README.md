# Survey

## Survey Data Analysis

Computers are commonly used to compile and analyze the results of surveys and opinion polls. Each response is a number from 1 to 9. The program computes for the mean, median and mode of the values. Start with a minimum of 10 responses. If there would be more responses, increase the size.
Mean – arithmetic average
Median – middle value
Mode – value that occurs most frequently

The following are the declarations that will be used by the program:
```c
int SIZE 10

typedef int* Statistician;

/*
 * Doubles the size of answer when it is full
 * Data should be sorted after every insertion.
 */
void add(Statistician answer, int *count, int *SIZE, int item);

float mean(Statistician answer, int count);

float median(Statistician answer, int count);

int max(Statistician answer, int count);

int min(Statistician answer, int count);

int range(Statistician answer, int count);

// Determines the mode by counting the number of responses of each type, then selecting the value with the greatest count.
void mode(int freq[], int *freqsize, Statistician answer, int count);

// Produces a histogram to aid in determining the mode graphically. Use asterisks to represents number of occurrences.
void histogram(Statistician answer, int count);
```