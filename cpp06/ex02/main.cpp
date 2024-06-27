#include "Identify.hpp"

int main()
{
	srand(time(NULL));

	Base *ABC = generate();
	identify_from_pointer(ABC);
	//identify_from_reference(*ABC);

	delete ABC;
}