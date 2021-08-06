/**

ArrayStats.h

Simple c array math routine for trend analysis, computes:
  - min / max / mean
  - range (diff 1st to last element)
  - trend (count of ascending / descending values in sequence)
  - greatest diff between two elements (increase / decrease)
  - count of consecutive (monotonic) sequence (increase / decrease)
  - culmulative count of incremental / decrementing sequences

In this version works only with array of floats

Useage:

*/


#ifndef ARRAY_STATS_H_
#define ARRAY_STATS_H_


#define LIBRARY_VERSION 1.1.0

//#include <Arduino.h> // capital A so it is error prone on case-sensitive filesystems



// struct providing results
struct ArrStatsResult
{
    float min;
    float max;
    float avg;
    int incCount;
    int decCount;
    int incSeqCount;
    int decSeqCount;
    float diff;
    float trend;
    float incMaxDiff;
    float decMaxDiff;
};


class ArrayStats {
    public:
      ArrayStats();
      ArrayStats(unsigned long s);
      void add(float f);
      float min();
      float max();
      float avg();
      void stats(struct ArrStatsResult *result);
      void printArray();
      //void printStats(struct arrStat result);

    protected:
      unsigned long idx = 0;  // array pointer
      unsigned long sz;      // array size
      float * v;   // array data
};


#endif //ARRAY_STATS_H_
