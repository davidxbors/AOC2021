#include "../common.h"

void shift_right (std::vector<u64>& v)
{
	for (size_t i = 0; i < v.size() - 1; i++)
		v[i] = v[i+1];
	v[v.size()-1] = 0;
}

u64 solve (u32 start, u32 end, std::vector<u64> school) 
{
	/* 
	   every day dec each counter and reset the fish that
	   get to 0
	*/
	for (u32 day = start; day < end; ++day) {
		u64 new_fish = school[0];
		shift_right(school);
		school[6] += new_fish;
		school[8] += new_fish;
	}
	return std::accumulate(school.begin(), school.end(), 0);
}

int main (void)
{
	std::cout << "AOC2021 Day 6 **" << std::endl;
	/* read numbers */
	/* treat the school as 9 kind of fish based on how many days they have till multiplication */
	std::ifstream input_file("input");
	std::vector<u64> school(9);
	std::for_each(std::istream_iterator<unsigned>(input_file), {},
		      [&](unsigned day) {++school[day];});
	/* solve */
	std::cout << "Part 1 => " << solve(0, 80, school) << "\n";
	std::cout << "Part 2 => " << solve(0, 256, school) << "\n";
	return 0;
}
