/**
 * Demonstrates use of ArrayStats class
 * to analyse a set of float values from a photoresistor
 *
 * Example Output:

    0	817.00
    1	833.00
    2	864.00
    3	897.00
    4	935.00
    5	947.00
    6	963.00
    7	975.00
    8	992.00
    9	997.00

    Array Stats:
    Min: 817.00
    Max: 997.00
    Mean: 922.00
    Diff: 180.00
    Trend: 9.00
    Inc Count: 9
    Dec Count: 0
    Inc Seq Count: 9
    Dec Seq Count: 0
    Inc Max Diff: 38.00
    Dec Max Diff: 0.00

 */

#include <ArrayStats.h>

const int ldrPin = A1;

// number of samples
#define AVG_ARR_SZ 10

// initialise sample array
float avg[AVG_ARR_SZ] = { 0 };
int avgPointer = 0; // array index

// instances of class & result struct
ArrayStats arrStat;
struct arrStat result;


void setup() {

  Serial.begin(115200);

  pinMode(ldrPin,INPUT);
}

void loop() {

  // read LDR value
  int v = 0;
  v = analogRead(ldrPin);
  //Serial.print("LDR0: ");
  Serial.print(v);
  Serial.println("");

  // append value to array
  avg[avgPointer++] = v;

  if (avgPointer == AVG_ARR_SZ)
  {
    // compute & display stats, reset array pointer
    arrStat.computeStats(avg, AVG_ARR_SZ, &result);
    arrStat.print(avg, AVG_ARR_SZ, result);
    avgPointer = 0;
  }

  delay(300);
}
