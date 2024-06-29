template<typename T>
int easyfind(T input, int tofind) //typename T::iterator easyfind(...)
{
	try
	{
		for (int i = 0; i < (int)input.size(); i++)
		{
			if (input[i] == tofind)
				return i;
		}
		throw std::runtime_error("number not found, returned ");
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what();
	}
	return -1;
}