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


#include <Arduino.h> // capital A so it is error prone on case-sensitive filesystems


// struct providing results
struct arrStat
{
    float min;
    float max;
    float mean;
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
      float computeMin(float v[], uint8_t sz);
      float computeMax(float v[], uint8_t sz);
      float computeAvg(float v[], uint8_t sz);
      void computeStats(float arr[], int sz, struct arrStat *result);
      void print(float arr[], uint8_t sz, struct arrStat result);
      void printArr(float arr[], uint8_t sz);
      void printStats(struct arrStat result);

    protected:

};


#endif //ARRAY_STATS_H_
