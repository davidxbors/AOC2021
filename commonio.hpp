#include <fstream>
#include <iostream>

/* prints a new line */
void print (void)
{
	std::cout << "\n";
}

template <typename T>
void print (T x)
{
	std::cout << x << " ";
}

/* prints std::vector */
template <typename T>
void print (std::vector<T> v)
{
	for (auto el : v)
		print(el);
}

/* prints std::vector<std::vector<>> */
template <typename T>
void print (std::vector<std::vector<T>> tdv)
{
	for (auto line : tdv) {
		print(line);
		print();
	}
}

/* writes to a file a new line */
void write (std::ofstream &file)
{
	file << "\n";
}

/* writes to a file std::vector */
template <typename T>
void write (std::ofstream &file, std::vector<T> v)
{
	for (auto el : v)
		file << el;
	write(file);
}

/* writes to a file std::vector<std::vector> */
template <typename T>
void write (std::ofstream &file, std::vector<std::vector<T>> tdv)
{
	for (auto line : tdv)
		write(file, line);
}
