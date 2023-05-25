#include <iostream>
#include <string>
#include <vector>
#include <map>

template <typename T>
struct MyAllocator {
	using value_type = T;

	MyAllocator() = default;

	template <typename U>
	MyAllocator(const MyAllocator<U>&) {}

	T* allocate(std::size_t n) {
		auto p = std::malloc(n * sizeof(T));
		if (!p)
			throw std::bad_alloc();
		return reinterpret_cast<T*>(p);
	}

	void deallocate(T* p, std::size_t) {
		std::free(p);
	}
};

template <typename Allocator>
void factorial(std::map <int, int, std::less<int>, Allocator > & factor);

int main()
{	
	std::map <int, int, std::less<int>, MyAllocator<std::pair <const int, int>> > factor_alloc;

	std::map <int, int> factor;

	factorial(factor);
	factorial(factor_alloc);

	for (const auto f : factor)
	{
		std::cout << f.first << " " << f.second << std::endl;
	}

	std::cout << "  " << std::endl;

	for (const auto f : factor_alloc)
	{
		std::cout << f.first << " " << f.second << std::endl;
	}

	std::vector <int> vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	std::vector<int, MyAllocator<int> > vec_alloc;

	for (int i = 0; i < 10; i++)
	{
		vec_alloc.push_back(i);
	}

	std::cout << "  " << std::endl;

	for (const auto f : vec)
	{
		std::cout << f << std::endl;
	}

	std::cout << "  " << std::endl;

	for (const auto f : vec_alloc)
	{
		std::cout << f << std::endl;
	}

	return 0;
}

template <typename Allocator>
void factorial(std::map <int, int, std::less<int>, Allocator > &factor)
{
	for (int i = 0; i < 10; i++)
	{
		factor[i] = 1;

		if (i == 0)
		{
			factor[i] = 1;
		}
		else
		{
			for (auto p = 1; p <= i; p++)
			{
				factor[i] = factor[i] * p;
			}
		}
	}
}
