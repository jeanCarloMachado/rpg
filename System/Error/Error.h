#include <string>

#ifndef SYSError
#define SYSError

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
		
		void setMessage(string message)
		{
			this->message = message;
		}
		
	private:
		string message;
	
	};
}

#endif