//Paging
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int convertDecimalToBinary(int n)
{
  int binaryNumber = 0;
  int remainder, i = 1, step = 1;
  while (n!=0)
  {
  remainder = n%2;
  n /= 2;
  binaryNumber += remainder*i;
  i *= 10;
  }
  return binaryNumber;
}

struct page_frame
{
  int page;
  int frame;
};

struct page_frame page_table[MAX];

int main()
{
  int no_of_processes, memory_parts_left;
  int main_memory, no_of_partitions, frame_size, i, j;
  int size_of_process[MAX], no_of_parts, size_of_last_part;
  int page_number, page_offset;

  printf("Enter size of memory and size of partitions: ");
  scanf("%d%d", &main_memory, &no_of_partitions);
  frame_size=main_memory/no_of_partitions;

  printf("Frame size: %d\n", frame_size);

  printf("Enter number of processes: ");
  scanf("%d", &no_of_processes);
  
  for(i=0;i<no_of_processes;i++)
  {
    printf("Enter size of process-%d: ", i+1);
    scanf("%d", &size_of_process[i]);
  }
  memory_parts_left=no_of_partitions;
  for(i=0;i<no_of_processes;i++)
  {
    no_of_parts=size_of_process[i]/frame_size; //page_size=frame_size
    size_of_last_part=size_of_process[i]%frame_size;

    if(size_of_last_part!=0)
      no_of_parts++;

    if(no_of_parts<=memory_parts_left)
    {
      memory_parts_left-=no_of_parts;
      printf("\nThere is space in memory for process-%d\n", i+1);

      //Assuming address as a 6-bit binary code, where the first 4 bits reflects page_number and last 2 bits reflects page_offset
      page_number=rand()%16;
      page_offset=rand()%4;
      printf("Randomly generated Logical Address - %d%d\n", convertDecimalToBinary(page_number), convertDecimalToBinary(page_offset));

      //Table entries:-
      for(j=0;j<16;j++)
      {
        page_table[j].page=j;
        page_table[j].frame=(2*j) + 1; //Random frame numbers
      }
      for(j=0;j<16;j++)
      {
        if(page_table[j].page == page_number)
        break;
      }
      printf("Number of parts used by process-%d: %d\n", i+1, no_of_parts);

      if((frame_size-size_of_last_part)==frame_size)
        printf("Fragment wasted: 0\n");
      else
        printf("Fragment wasted: %d\n", frame_size-size_of_last_part);

      printf("Physical Address: %d%d\n", convertDecimalToBinary(page_table[j].frame), convertDecimalToBinary(page_offset));
    }
    else
    {
      printf("\nNo space in main memory for process-%d\n", i+1);
    }
  }
  return 0;
}
