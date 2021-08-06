#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "./ArrayStats/ArrayStats.h"



int main()
{

  printf("arrayStats.c begin...\n");

  int s = 10;
  ArrayStats sample1(s);

  int i = 0;
  int n = 1;
  int milli_seconds=n*1000;
  time_t start, end;
  start=time(0);
  while(1)
  {

    if(time(0)-start==n)
    {
      printf("Exec...");
      printf("%lld\n", (long long) time(NULL));

      float f = (float) rand();
      sample1.add(f);
      i++;

      if (i == s)
      {
        sample1.printArray();

        ArrStatsResult result;
        sample1.stats(&result);

        float min;
        float max;
        float mean;

        printf("Avg: %f, Min: %f, Max: %f \n",  result.avg, result.min, result.max);

        printf("Diff: %f, Trend: %f\n",  result.diff, result.trend);

        printf("Inc: %d, Dec: %d, Seq Inc: %d, Seq Dec: %d\n", result.incCount, result.decCount, result.incSeqCount, result.decSeqCount);

        i = 0;
      }
      start=start+n;
    }
  }
}
