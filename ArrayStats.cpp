#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#include "ArrayStats.h"


ArrayStats::ArrayStats() {}

ArrayStats::ArrayStats(const unsigned long s)
{
	_idx = 0;
	_sz = s;
	_v = (float*) malloc(_sz * sizeof(float));
}

ArrayStats::~ArrayStats()
{
  if (_v != NULL) free(_v);
}

void ArrayStats::add(const float f)
{
	_v[_idx++] = f;
	if (_idx == _sz)
	{
		_idx = 0;
	}
}


float ArrayStats::min()
{
	float m = 0;
  for(int i = 0; i<_sz; i++)
  {
    m = ((i	 == 0) || (_v[i] < m)) ? _v[i] : m;
  }
  return m;
}

float ArrayStats::max()
{
	float m = 0;
  for(int i = 0; i<_sz; i++)
  {
    m = (_v[i] > m) ? _v[i] : m;
  }
  return m;

}

// compute simple average from array of values
float ArrayStats::avg()
{
	float sum = 0, avg;
  for(int i = 0; i<_sz; i++)
  {
    sum += _v[i];
  }
  return avg = sum / _sz;
}

unsigned long ArrayStats::getIndex()
{
	return _idx;
}

bool ArrayStats::isFull()
{
	return (_idx == _sz -1) ? true : false;
}


void ArrayStats::stats(struct ArrayStatsResult *result)
{

	// init result struct values
  result->min = 0;
  result->max = 0;
  result->avg = 0;
  result->incSeqCount = 0;
  result->decSeqCount = 0;
  result->incCount = 0;
  result->decCount = 0;
  result->trend = 0;
  result->incMaxDiff = 0;
  result->decMaxDiff = 0;

  result->min = min();
  result->max = max();
  result->avg = avg();
  // tail = head - (sz -1)
  // if tail < 0, tail = sz - tail
  result->diff = _v[_sz-1] - _v[0]; // difference between last / first data points

  int period = 1;

  // sequential (monotonic) & cumulative increase / decrease counters
  int incSeqCount = 0;
  int decSeqCount = 0;
  int incCumCount = 0;
  int decCumCount = 0;

  for(int i = _sz; i > 1; i--)
  {
    float curr = _v[_sz - i + period];
    float prev = _v[_sz - i];

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


void ArrayStats::printArray()
{
	printf("Array Size: %lu\n", _sz);
	printf("Array Index: %lu\n",_idx);

	for(unsigned long i=0; i<_sz; i++)
	{
		printf("%lu \t %f\n", i, _v[i]);
	}

}

/*
void ArrayStats::printStats(struct arrStat result)
{
	/*
	Serial = &Serial;

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
	*/
