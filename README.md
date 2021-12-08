# Adevent of Code 2021

This is the home of my Advent of Code 2021 solutions. I will try to solve all of the challenges if my free time allows it.

## Day 5

For day 5 I had two solutions in mind. One involved more time-complexity, one more space-complexity. As I initially misinterpreted how big the space complexity of the problem is I went with the more time complex one.

## Day 6

Time of running for day 6: `0.01 sec`. I achieved O(days * 9) complexity by looking at fish as quantities of the same kind (same kind meaning equal number of days untill multiplication).

## Day 7

`0.05 sec` (and even `0.03` with one run) achieved today. Part 1 was obviously using the median and this made me think that part 2 will also use statistics concepts. I observed that for the example the mean was the correct position so decided to try an aglorithm that uses the mean for the actual input too. It worked and using this configuration I obtained the time stated previously. After finishing the challenge I read a demonstration that proved that the mean, while very close to the actual answer is not exact[1] so I also added a "naive" approach that should work with trickier inputs[2] too. (of course it takes considerably longer)

## Day 8

`0.07 sec`.

Part 1 was really easy and was done in O(n) complexity. For part 2 I used the fact that the more complicated patterns (of length 5 and 6) can be differentiated between by comparing them with patterns already found. So, there are 3 different categories of patterns:

* Basic patterns: these are the ones that can be matched to digits using their length as a criterion (the ones that we need to find for part1): 1, 7, 4, 8

* Medium patterns: these are patterns that can be matched to digits by their length (the only length compatible with this definition is 6) and by comparing them only to basic patterns:
  * 9 -> we can match a pattern to 9 if its length is 6 and it contains all segments of 4
  * 0 -> we can match a pattern to 0 if its length is 6 and it contains all segments of 1
  * 6 -> we can match a pattern to 6 if its length is 6 and the previous match attempts failed

* Hard patterns: these are patterns that can be matched to using digits by their length (the only length compatible with this definitions is 5) and by comparing them to basic **and medium** patterns:
  * 3 -> we can match a pattern to 3 if its length is 5 and it contains all segments of 1
  * 5 -> we can match a pattern to 5 if its length is 5 and all its segments are contained by 6
  * 2 -> we can match a pattern to 6 if its length is 5 and the previous match attempts failed

With this in mind we will need three iterations through the first 10 patterns given on each line to map all patterns to digits. (we need to first map basic patterns, then medium, then hard because they have dependencies with each other) There might be some better matching criteria which would allow us to use only two iterations but I didn't have time to think about them / read about them. If I'll discover them I'll make an update.

## References

[1](https://old.reddit.com.adventofcode/comments/rar7ty/2021_day_7_solutions/hnkbtug/)

[2] -> take for example the input "0,0,0,0,0,0,0,0,0,16": it's mean is 1.6 while the answer is 1
