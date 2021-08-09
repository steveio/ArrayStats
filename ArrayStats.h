/**

ArrayStats.h

Simple c array math routine for real time data trend analysis, computes:
  - min / max / mean
  - range (diff 1st to last element)
  - trend - signed sum of ascending / descending steps in sequence
  - greatest diff between two elements (increase / decrease)
  - count of consecutive (monotonic) sequence steps(increase / decrease)
  - culmulative count of incremental / decrementing sequences

Useage:

*/


#ifndef ARRAY_STATS_H_
#define ARRAY_STATS_H_


#define LIBRARY_VERSION 1.1.0



// struct encapsulating result data
struct ArrayStatsResult
{
    float min;
    float max;
    float avg;
    float stdDev;
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
      ArrayStats(const unsigned long s);
      ~ArrayStats();
      void add(const float f);
      float min();
      float max();
      float avg();
      float stdDev();
      void stats(struct ArrayStatsResult *result);
      unsigned long getIndex();
      bool isFull();
      void printArray();
      //void printStats(struct arrStat result);

    protected:
      unsigned long _idx; // array pointer
      unsigned long _sz;      // array size
      float * _v;             // array data, circular buffer
};


#endif //ARRAY_STATS_H_
