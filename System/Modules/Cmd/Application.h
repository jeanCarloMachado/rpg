#ifndef __SYSCMDApplication__
#define __SYSCMDApplication__

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "System/Language/Language.h"
//#include "System/Router/Cmd/RouterMgr.cpp"
#include "System/Application/ApplicationInterface.h"

namespace SystemCmd
{
	class Application : public System::ApplicationInterface
	{

	public:
		// int init() 
		// {
		// 	return 1;
		// }

		// int run(void)
		// {
		// 	routerMgr.listen();

		// 	return 1;
		// }

		// int setParams(char ***params) 
		// {
		// 	this->params = &**params;
		// }

	protected:
		//SystemCmd::RouterMgr routerMgr;
	};
}

#endif