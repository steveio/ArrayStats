#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "./ArrayStats/ArrayStats.h"



int main()
{

  printf("arrayStats.c begin...\n");

  pid_t pid = getpid();

  const unsigned long sz = 10;
  ArrayStats sample1(sz);
  ArrayStatsResult result;

  float f;
  struct timeval t1, t2;;
  unsigned long start = 0.0, curr = 0.0, tdiff = 0.0, loopCount = 0, n = 10000.0;

  gettimeofday(&t1, NULL);
  start = (unsigned long) t1.tv_usec;

  printf("Start: %lu\n", start);

  while(1)
  {

    gettimeofday(&t2, NULL);
    curr = (unsigned long) t2.tv_usec;

    /*
    printf("Curr: %lu\n", curr);
    printf("Start: %lu\n", start);
    printf("TimeDiff: %lu\n", (curr - start));
    */

    if (curr - start > n)
    {

      f = (float) (rand() % (100 + 1 - 0) + 0);

      sample1.add(f);

      if (sample1.isFull())
      {

        sample1.printArray();
        sample1.stats(&result);

        printf("Avg: %f, Min: %f, Max: %f, StdDev: %f \n",  result.avg, result.min, result.max, result.stdDev);

        printf("Diff: %f, Trend: %f\n",  result.diff, result.trend);

        printf("Inc: %d, Dec: %d, Seq Inc: %d, Seq Dec: %d\n", result.incCount, result.decCount, result.incSeqCount, result.decSeqCount);

      }
      loopCount++;
      //printf("pid: %lu,Loop: %llu\n", pid, loopCount);

      gettimeofday(&t1, NULL);
      start = (unsigned long) t1.tv_usec;
    }
  }
  exit(0);
}
