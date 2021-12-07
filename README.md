# Adevent of Code 2021

This is the home of my Advent of Code 2021 solutions. I will try to solve all of the challenges if my free time allows it.

## Day 5

For day 5 I had two solutions in mind. One involved more time-complexity, one more space-complexity. As I initially misinterpreted how big the space complexity of the problem is I went with the more time complex one.

## Day 6

Time of running for day 6: `0.01 sec`. I achieved O(days * 9) complexity by looking at fish as quantities of the same kind (same kind meaning equal number of days untill multiplication).

## Day 7

`0.05 sec` (and eve `0.03` with one run) achieved today. Part 1 was obviously using the median and this made me think that part 2 will also use statistics concepts. I observed that for the example the mean was the correct position so decided to try an aglorithm that uses the mean for the actual input too. It worked and using this configuration I obtained the time stated previously. After finishing the challenge I read a demonstration that proved that the mean, while very close to the actual answer is not exact[1] so I also added a "naive" approach that should work with trickier inputs[2] too. (of course it takes considerably longer)


## References

[1](old.reddit.com.adventofcode/comments/rar7ty/2021_day_7_solutions/hnkbtug/)

[2] -> take for example the input "0,0,0,0,0,0,0,0,0,16": it's mean is 1.6 while the answer is 1
