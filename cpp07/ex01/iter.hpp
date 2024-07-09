#ifndef ITER_HPP
#define ITER_HPP

template<typename F>
void add2(F& value)
{
	value += 2;
}

template<typename T, typename F>
void iter(T *addr, int len, void (*func)(F&))
{
	for (int i = 0; i < len; i++)
		func(addr[i]);
}

#endif