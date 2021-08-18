#include <ArrayStats.h>
#include <ArrayStatsContainer.h>


ArrayStatsContainer sensor1Stats(20, 60, 24);  // number of samples per min, hour, day
ArrayStatsContainerResult result;


void setup() {}

void loop() 
{

  Serial.begin(115200);

  float n, lo, hi;
  lo = 0;
  hi = 50;

  for(unsigned long i=0; i<=28800; i++)
  {
    n = (float) random(lo, hi) / 100;
    Serial.println(n);

    sensor1Stats.add(n);

    if (i % 20 == 0)
    {
      sensor1Stats.stats(&result);

      Serial.println("1 Minute Stats:");
      printStats(result.min);
    }

    if (i % 60 == 0)
    {
      sensor1Stats.stats(&result);

      Serial.println("1 Hour Stats:");
      printStats(result.hour);
    }

    if (i % 24 == 0)
    {
      sensor1Stats.stats(&result);

      Serial.println("1 Day Stats:");
      printStats(result.day);
    }

  }
}

void printStats(struct ArrayStatsResult result)
{

  Serial.print("Min: "); Serial.println(result.min);
  Serial.print("Max: "); Serial.println(result.max);
  Serial.print("Mean: "); Serial.println(result.avg);
  Serial.print("Diff: "); Serial.println(result.diff);
  Serial.print("Std Dev: "); Serial.println(result.stdDev);
  Serial.print("Trend: "); Serial.println(result.trend);

  Serial.print("Inc Count: "); Serial.println(result.incCount);
  Serial.print("Dec Count: "); Serial.println(result.decCount);

  Serial.print("Inc Seq Count: "); Serial.println(result.incSeqCount);
  Serial.print("Dec Seq Count: "); Serial.println(result.decSeqCount);

  Serial.print("Inc Max Diff: "); Serial.println(result.incMaxDiff);
  Serial.print("Dec Max Diff: "); Serial.println(result.decMaxDiff);

  Serial.println("");
}
