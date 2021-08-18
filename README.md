Arduino Array Stats

Simple c++ class for Arduino to compute array math for running trend analysis.

Designed to solve problem of maintaining statistics for sensor data either a single n sized array or for data sampled in cyclic buffer at second, minute and hour intervals.

Similar to https://www.arduino.cc/reference/en/libraries/runningaverage/ with enhancements to answer questions 
- were values rising / falling?  
- by what magnitude?  
- what was rate of change?

Also, includes a container wrapper class providing a simple API to maintain time delimited samples. 

Computes:

- min / max / mean
- range (diff 1st to last element)
- trend (signed count of ascending / descending values in sequence)
- greatest diff between two elements (magnitude increase / decrease)
- count of consecutive (monotonic) sequence steps (increase / decrease)
- culmulative count of incremental / decrementing steps in sequence

Compatible with c++ and Arduino (ESP32) architectures.

Useage:

examples/ArrayStats - example to maintain single n sized float array

examples/ArrayStatsContainer - demonstrates populating n sized minute, hour & day sample arrays


Example Output:

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

