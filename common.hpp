#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <limits>
#include <string>
#include <array>
#include <set>
#include <stack>
#include <map>

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using s8 = std::int8_t;
using s16 = std::int16_t;
using s32 = std::int32_t;
using s64 = std::int64_t;

using f32 = float;
using f64 = double;

using sz = size_t;

/*
 * convert std::vector<u8> to std::vector<T> specified when calling function
 */
template <typename T>
std::vector<T> convert_vchar_v (std::vector<u8> v)
{
	std::vector<T> result;
	for (auto el : v)
		result.push_back(static_cast<T>(el - 48));
	return result;
}

template <typename K, typename V>
void print (std::map<K, V> m)
{
	for (auto e : m) {
		std::cout << e.first << " -> [ ";
		print(e.second);
		std::cout << " ]\n";
	}
}
template <typename T>
u64 contains (std::vector<T> v, T el)
{
	u64 result = 0;
	for (auto e : v)
		result += (e == el);
	return result;
}
