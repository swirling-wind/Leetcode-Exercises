#include <climits>

inline unsigned int get_abs(int input)
{
	const int mask = input >> (sizeof(int) * CHAR_BIT - 1); //limits.h
	return (input ^ mask) - mask;
}

inline int get_minimum(int x, int y)
{
	return y ^ ((x ^ y) & -(x < y));
}

inline int get_maximum(int x, int y)
{
	return x ^ ((x ^ y) & -(x < y));
}