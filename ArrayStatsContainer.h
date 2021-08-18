/**

ArrayStatsContainer.h

Wrapper for ArrayStats library to maintain rolling second, minute & hour statistics

Useage:

*/


#ifndef ARRAY_STATS_CONTAINER_H_
#define ARRAY_STATS_CONTAINER_H_


#define LIBRARY_VERSION 1.1.0

struct ArrayStatsContainerResult
{
  ArrayStatsResult min;
  ArrayStatsResult hour;
  ArrayStatsResult day;
};


class ArrayStatsContainer {
    public:
      ArrayStatsContainer();
      ArrayStatsContainer(const int m, const int h, const int d);
      void add(const float f);
      void stats(struct ArrayStatsContainerResult *result);
      ~ArrayStatsContainer();

    protected:
      ArrayStats _min;
      ArrayStats _hour;
      ArrayStats _day;
};


#endif //ARRAY_STATS_H_
