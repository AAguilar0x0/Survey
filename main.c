#include <stdio.h>
#include <stdlib.h>
#include "survey.h"

int ascendCmpFunc(const void * a, const void * b) {
   return (*(const int*)a  > *(const int*)b) - (*(const int*)a < *(const int*)b);
}

int main(int argc, char *argv[]) {
	int SIZE = 10 ,count = 0, item, i, freqsize;
	int *freq = (int*)calloc(SIZE,sizeof(int));
	char opt = 'y';
	Statistician answer = (Statistician)calloc(SIZE,sizeof(int));
	
	printf("\t\tEnter responses\n\n");
	
	for(i=0;i<SIZE;i++){
		fflush(stdin);
		printf("\tResponse no. %d: ",i+1);
		scanf("%d",&item);
		add(&answer,&count,&SIZE,item);
	}

	while(1){
		fflush(stdin);
		printf("\n\tDo you wan't to add another entry?\n\t'y'=Yes/'n'=No> ");
		scanf("%c",&opt);
		opt = tolower(opt);
		if(opt=='n')
			break;
		fflush(stdin);
		if(opt=='y'){
			printf("\n\tResponse no. %d: ",1 + i++);
			scanf("%d",&item);
			add(&answer, &count, &SIZE,item);
		}
	}
	qsort(answer, count, sizeof(int), ascendCmpFunc);
	printf("\n\tData:\t");
	for(i=0;i<count;i++){
		printf("%d ",answer[i]);
	}
	
	printf("\n\tMin:\t%d",min(answer,count));
	printf("\n\tMax:\t%d",max(answer,count));
	printf("\n\tRange:\t%d",range(answer,count));
	printf("\n\tMean:\t%.2f",mean(answer,count));
	printf("\n\tMedian:\t%.2f",median(answer,count));
	printf("\n\tMode/s:\t");mode(freq, &freqsize, answer,count);
	printf("\n\tHistorgram:\n");
	histogram(answer,count);
	
	free(freq);
	free(answer);
	
	return 0;
}
