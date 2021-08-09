
#include <ArrayStats.h>


void setup() {

}

void loop() 
{

  Serial.begin(115200);

  int a,b,c;
  a = 20;
  b = 60;
  c = 24;

  ArrayStats minAvg(a);
  ArrayStats hourAvg(b);
  ArrayStats dayAvg(c);

  float n, lo, hi;
  lo = 0;
  hi = 50;

  for(unsigned long i=0; i<=28800; i++)
  {
    n = (float) random(lo, hi) / 100;
    Serial.println(n);
    minAvg.add(n);

    if (minAvg.isFull())
    {
      ArrayStatsResult resultMin;
      minAvg.stats(&resultMin);
      Serial.println("1 Minute Stats:");
      printStats(resultMin);

      hourAvg.add(minAvg.avg());
      if (hourAvg.isFull())
      {
        ArrayStatsResult resultHour;
        hourAvg.stats(&resultHour);
        Serial.println("1 Hour Stats:");
        printStats(resultHour);
        delay(5000);


        dayAvg.add(hourAvg.avg());
        if (dayAvg.isFull())
        {
          ArrayStatsResult resultDay;
          dayAvg.stats(&resultDay);
          Serial.println("1 Day Stats:");
          printStats(resultDay);
          delay(5000);
        
        }
      }
    }
  }
}

void printStats(struct ArrayStatsResult result)
{

  Serial.print("Min: "); Serial.println(result.min);
  Serial.print("Max: "); Serial.println(result.max);
  Serial.print("Mean: "); Serial.println(result.avg);
  Serial.print("Diff: "); Serial.println(result.diff);
  Serial.print("Trend: "); Serial.println(result.trend);

  Serial.print("Inc Count: "); Serial.println(result.incCount);
  Serial.print("Dec Count: "); Serial.println(result.decCount);

  Serial.print("Inc Seq Count: "); Serial.println(result.incSeqCount);
  Serial.print("Dec Seq Count: "); Serial.println(result.decSeqCount);

  Serial.print("Inc Max Diff: "); Serial.println(result.incMaxDiff);
  Serial.print("Dec Max Diff: "); Serial.println(result.decMaxDiff);

  Serial.println("");
}
