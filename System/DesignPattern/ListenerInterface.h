#ifndef _SYSListenerInterface__
#define _SYSListenerInterface__

#include <vector>

#include "System/Language/Language.h"

namespace System
{
	class ListenerInterface 
	{	
	public:	
		virtual void listen() = 0;
	};	
}

#endif