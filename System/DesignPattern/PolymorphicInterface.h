#ifndef _SYSPolymorphicInterface__
#define _SYSPolymorphicInterface__

#include <vector>
#include "System/Language/Language.h"

namespace System
{
	class PolymorphicInterface
	{	
	public:	
		template<typename T>
		void getInstance(std::vector<T> params) {}
	};	
}

#endif