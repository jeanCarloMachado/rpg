#ifndef SYSError
#define SYSError

#include <string>

using namespace std;

namespace System
{

	class Error 
	{
	public:
		string getMessage()
		{
			return this->message;
		}
		
		void setMessage(const string message)
		{
			this->message = message;
		}
		
	private:
		string message;
	
	};
}

#endif