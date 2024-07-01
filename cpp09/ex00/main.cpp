//La map in C++ mantiene automaticamente le chiavi in ordine crescente, quindi trovare la data più vicina diventa una questione di utilizzare le funzioni di ricerca fornite dalla libreria standard, come lower_bound o upper_bound, per trovare l'elemento più vicino alla data di interesse.
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./bitcoin [data.csv]" << std::endl;
		return 1;
	}
	BitcoinExchange exchange(argv[1]);
	exchange.btc();
}