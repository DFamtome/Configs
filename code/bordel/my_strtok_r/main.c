#include "my_strtok_r.h"

int main()
{
	
	char data[] = "Token1 Token2";
	char* rest = data;
	const char* delim = " ";
	my_strtok_r(rest, delim, &rest);


	return 0;
}
