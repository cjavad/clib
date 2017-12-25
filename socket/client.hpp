//check if defined
#ifndef _CLIBSOCK_
// if not define
#define _CLIBSOCK_
// and include
#ifdef _WIN32
	#include "src/client/win_client.hpp"
#else
	#include "src/client/unix_client.hpp"
#endif //endif ifdef include 
#endif //endif ifndef