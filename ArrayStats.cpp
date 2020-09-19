#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#include "ArrayStats.h"


ArrayStats::ArrayStats () {}


float ArrayStats::computeMin(float v[], uint8_t sz)
{
	float m = 0;
  for(int i = 0; i<sz; i++)
  {
    m = ((i	 == 0) || (v[i] < m)) ? v[i] : m;
  }
  return m;
}

float ArrayStats::computeMax(float v[], uint8_t sz)
{
	float m = 0;
  for(int i = 0; i<sz; i++)
  {
    m = (v[i] > m) ? v[i] : m;
  }
  return m;

}

// compute simple average from array of values
float ArrayStats::computeAvg(float v[], uint8_t sz)
{
	float sum = 0, avg;
  for(int i = 0; i<sz; i++)
  {
    sum += v[i];
  }
  return avg = sum / sz;
}

/**
 * Simple c array math routine to compute:
 *  - min / max / mean
 *  - range (diff 1st to last element)
 *  - trend (count of ascending / descending values in sequence)
 *  - greatest diff between two elements (increase / decrease)
 *  - count of consecutive (monotonic) sequence (increase / decrease)
 *  - culmulative count of incremental / decrementing sequences
 *
 * @param float array
 * @param int sz number of elements
 * @param struct arraStat (pointer)
 * @return void
 *
 */
void ArrayStats::computeStats(float arr[], int sz, struct arrStat *result)
{

	// init result struct values
  result->min = 0;
  result->max = 0;
  result->mean = 0;
  result->incSeqCount = 0;
  result->decSeqCount = 0;
  result->incCount = 0;
  result->decCount = 0;
  result->trend = 0;
  result->incMaxDiff = 0;
  result->decMaxDiff = 0;

  result->min = computeMin(arr, sz);
  result->max = computeMax(arr  , sz);
  result->mean = computeAvg(arr, sz);
  // tail = head - (sz -1)
  // if tail < 0, tail = sz - tail
  result->diff = arr[sz-1] - arr[0]; // difference between last / first data points

  int period = 1;

  // sequential (monotonic) & cumulative increase / decrease counters
  int incSeqCount = 0;
  int decSeqCount = 0;
  int incCumCount = 0;
  int decCumCount = 0;

  for(int i = sz; i > 1; i--)
  {
    float curr = arr[sz - i + period];
    float prev = arr[sz - i];

    // diff 1st to last only valid when arr pointer is at last position
    float diff = curr - prev;
    if (diff > 0)
    {
      result->trend++;
    } else {
      result->trend--;
    }

    if ( curr > prev) // increase (rise)
    {
      incCumCount++;
      incSeqCount++;
      if (incSeqCount > result->incSeqCount)
      {
        result->incSeqCount = incSeqCount;
      }
      decSeqCount = 0;

      diff = curr - prev;
      if (diff > result->incMaxDiff)
      {
        result->incMaxDiff = diff;
      }

    } else if (curr < prev) { // decrease (fall)
      decCumCount++;
      decSeqCount++;
      if (decSeqCount > result->decSeqCount)
      {
        result->decSeqCount = decSeqCount;
      }
      incSeqCount = 0;

      diff = prev - curr;
      if (diff > result->decMaxDiff)
      {
        result->decMaxDiff = diff;
      }
    }
  }

  result->incCount = incCumCount;
  result->decCount = decCumCount;

}

void ArrayStats::print(float arr[], uint8_t sz, struct arrStat result)
{
	ArrayStats::printArr(arr, sz);
	ArrayStats::printStats(result);
}

void ArrayStats::printArr(float arr[], uint8_t sz)
{
	for(int i=0; i<sz; i++)
	{
		Serial.print(i);
		Serial.print("\t");
		Serial.println(arr[i]);
	}
}

void ArrayStats::printStats(struct arrStat result)
{
	Serial.println("Array Stats:");


  Serial.print("Min: "); Serial.println(result.min);
  Serial.print("Max: "); Serial.println(result.max);
  Serial.print("Mean: "); Serial.println(result.mean);
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
