#include "ArrayStats.h"
#include "ArrayStatsContainer.h"


ArrayStatsContainer::ArrayStatsContainer() {}

ArrayStatsContainer::ArrayStatsContainer(const int m, const int h, const int d)
{
	ArrayStats minArray(m);
	ArrayStats hourArray(h);
	ArrayStats dayArray(d);

	_min = minArray;
	_hour = hourArray;
	_day = dayArray;
}

ArrayStatsContainer::~ArrayStatsContainer() {}

void ArrayStatsContainer::add(const float f)
{
	_min.add(f);
	if (_min.isFull())
	{
		_hour.add(_min.avg());
		if (_hour.isFull())
		{
			_day.add(_hour.avg());
		}
	}
}

void ArrayStatsContainer::stats(struct ArrayStatsContainerResult *result)
{
	ArrayStatsResult resultMin;
	_min.stats(&resultMin);
	result->min = resultMin;

	ArrayStatsResult resultHour;
	_hour.stats(&resultHour);
	result->hour = resultHour;

	ArrayStatsResult resultDay;
	_day.stats(&resultDay);
	result->day = resultDay;
}
