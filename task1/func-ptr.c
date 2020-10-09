#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

#include "process.h"
#include "util.h"

#define DEBUG 0			//change this to 1 to enable verbose output

/**
 * Signature for an function pointer that can compare
 * You need to cast the input into its actual 
 * type and then compare them according to your
 * custom logic
 */
typedef int (*Comparer) (const void *a, const void *b);
/**
 * compares 2 processes
 * You can assume: 
 * - Process ids will be unique
 * - No 2 processes will have same arrival time
 */
int my_comparer(const void *this, const void *that)
{
	//TODO: IMPLEMENT ME! 
  int l = ((Process *)this)->arrival_time; 
  int r = ((Process *)that)->arrival_time;  
  return (l - r); 
}

int my_comparer_2(const void *this, const void *that)
{
	//TODO: IMPLEMENT ME! 
  int l = ((Process *)this)->priority; 
  int r = ((Process *)that)->priority;  
  
  if(l == r) {
    return my_comparer(this, that);
  }
  return (r - l); 
}

int main(int argc, char *argv[])
{

	if (argc < 2) {
		   fprintf(stderr, "Usage: ./func-ptr <input-file-path>\n");
		   fflush(stdout);
		   return 1;
	}

	/*******************/
	/* Parse the input */
	/*******************/
	FILE *input_file = fopen(argv[1], "r");
	if (!input_file) {
		   fprintf(stderr, "Error: Invalid filepath\n");
		   fflush(stdout);
		   return 1;
	}

	Process *processes = parse_file(input_file);

	/*******************/
	/* sort the input  */
	/*******************/
	Comparer process_comparer = &my_comparer;       //arival time
  Comparer process_comparer_2 = &my_comparer_2;   //priority time
  
#if DEBUG
  int i;
  printf("Pid Priority Arival Time\n"
	for (i = 0; i < P_SIZE; i++) {
		    printf("%d (%d, %d) ",
				processes[i].pid,
				processes[i].priority, processes[i].arrival_time);
	}
	printf("\n");
#endif

	qsort(processes, P_SIZE, sizeof(Process), process_comparer); //sort by arrival time
	/******************************************/
	/* print the sorted data by arrival time  */
	/******************************************/
  int i;
  printf("Pid Priority Arival Time\n");
	for (i = 0; i < P_SIZE; i++) {
		    printf("%d (%d, %d)\n",
				processes[i].pid,
				processes[i].priority, processes[i].arrival_time);
	}
	fflush(stdout);
	fflush(stderr);

    qsort(processes, P_SIZE, sizeof(Process), process_comparer_2); //sort by priority 


  /**************************************/
	/* print the sorted data by priority  */
	/**************************************/
  int j;
  printf("\n\n");
  printf("Pid Priority Arival Time\n");
	for (j = 0; j < P_SIZE; j++) {
		    printf("%d (%d, %d)\n",
				processes[j].pid,
				processes[j].priority, processes[j].arrival_time);
	}
	fflush(stdout);
	fflush(stderr);
  
	/************/
	/* clean up */
	/************/
	free(processes);
	fclose(input_file);
	return 0;
}
