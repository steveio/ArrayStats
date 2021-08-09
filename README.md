Arduino Array Stats

Simple c++ class for Arduino compute array math for trend analysis.

Designed to solve problem of maintaining statistics for sensor data sampled at second, minute and hour intervals.

Similar to https://www.arduino.cc/reference/en/libraries/runningaverage/ with enhancements to answer questions 
- were values rising / falling?  
- by what magnitude?  
- what was rate of change?

Computes:

- min / max / mean
- range (diff 1st to last element)
- trend (signed count of ascending / descending values in sequence)
- greatest diff between two elements (magnitude increase / decrease)
- count of consecutive (monotonic) sequence steps (increase / decrease)
- culmulative count of incremental / decrementing steps in sequence

Compatible with c++ and Arduino (ESP32) architectures.

Useage:
  See examples/

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
