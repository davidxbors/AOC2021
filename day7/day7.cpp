#include "../common.h"

s32 fuel_func (u64 distance)
{
	s32 result = 0;
	for (s32 i = 1; i <= distance; i++)
		result += i;
	return result;
}

int main (void)
{
	std::cout << "AOC2021 Day 7 **" << std::endl;
	std::ifstream input_file("data/day7");
	std::vector<u64> crabs((std::istream_iterator<u64>(input_file)), std::istream_iterator<u64>());

	const auto SolvePart = [&] (u8 part) {
		if (part == 1) {
			std::sort(crabs.begin(), crabs.end());
			u64 median = (crabs.size() % 2) ? crabs.at((crabs.size()-1)/2) : ((crabs.at(crabs.size() / 2) + crabs.at((crabs.size() / 2) - 1)) / 2);
			return std::accumulate(crabs.begin(), crabs.end(), 0, [&](u64 a, u64 b) {
				return a + std::labs((b - median)); 
			});
		} else {
# if 0
			s32 fuel = std::numeric_limits<int>::max();
			for (u64 i = 0; i < *std::max_element(crabs.begin(), crabs.end()); i++) {
				s32 _fuel = 0;
				for (auto crab : crabs)
					_fuel += fuel_func(std::labs(crab - i));
				if (_fuel < fuel)
					fuel = _fuel;
			}
			return fuel;
#endif
			u64 avg = std::round((double)std::accumulate(crabs.begin(), crabs.end(), 0) / crabs.size());
			return std::accumulate(crabs.begin(), crabs.end(), 0, [&](u64 a, u64 b) {
				return a + fuel_func(std::labs((b - avg))); 
			});
		}
	};
	std::cout << "Part 1 => " << SolvePart(1) << std::endl;
	std::cout << "Part 2 => " << SolvePart(2) << std::endl;
	return 0;
}
