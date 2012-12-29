#ifndef __SYSBOOTSTRAP__
#define __SYSBOOTSTRAP__


#include "Application.h"


class Bootstrap
{
public:
	virtual void init(Application* app);

	virtual void _init(Application* app);

};

#endif
