
#ifndef SYSSemaphore
#define SYSSemaphore

using namespace std;

	
class Semaphore 
{
public:
	Semaphore(void);
	//virtual ~Semaphore(void);
	
	enum Status {
		INITIALISING,
		PLAYING,
		MENU
	};
	
	Semaphore::Status getCurrentStatus()
	{
		return this->currentStatus;
	}
	
	Semaphore* setCurrentStatus(Semaphore::Status currentStatus)
	{
		this->currentStatus = currentStatus;
		return this;
	}
		
		
protected:

private:
	Status currentStatus;
};
#endif
