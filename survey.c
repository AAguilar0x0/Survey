#include "survey.h"
#include <stdio.h>
#include <stdlib.h>

void add(Statistician *answer, int *count, int *SIZE, int item){
	if(*count>=*SIZE){
		*SIZE = *SIZE * 2;
		*answer =realloc(*answer,sizeof(int) * *SIZE);
	}
	*(*answer + *count) = item;
	++(*count);
}

int max(Statistician answer, int count){
	return answer[count-1];
}

int min(Statistician answer, int count){
	return answer[0];
}

int range(Statistician answer, int count){
	return answer[count-1] - answer[0];
}

float mean(Statistician answer, int count){
	int sum = 0,i;
    for (i = 0; i < count; i++)  
        sum += answer[i]; 
    return (float)sum/(float)count; 
}

float median(Statistician answer, int count){	
    return (count % 2 != 0) ? 
	(float)answer[count/2] : 
	(float)(answer[(count-1)/2] +answer[count/2])/2.0;   
}

void mode(int freq[], int *freqsize, Statistician answer, int count){
	int i,max;
	for(i=0;i<count;i++)
		freq[answer[i]-1]++;
	
	max =  freq[0];
	
	for(i=1;i<10;i++)
		if(max < freq[i])
			max = freq[i];
			
	for(i=0;i<10;i++)
		if(freq[i] == max)
			printf("%d ",i+1);
}

void histogram(Statistician answer, int count){
	int *tally = calloc(count, sizeof(int));
	int i,j;
	for(i = 0; i < count; i++)
		if(answer[i])
			tally[answer[i]-1]++;
	for(i = 0; i < count; i++)
		printf("\t\t[%d] = %d\n",i + 1,tally[i]);
	free(tally);
}
