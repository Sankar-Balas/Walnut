#include "Log.h"


namespace Walnut {
	Log* Log::m_Instance = nullptr;

	Log::Log() 
	{
		//Empty Cons
	}
	
	Log::~Log() 
	{
		//Empty Dest
	}

	void Log::Trace(const char * msg)
	{
		std::cout << "[Trace]:" << msg << std::endl;
	}
	void Log::Warning(const char * msg)
	{
		std::cout << "[Warning]:" << msg << std::endl;
	}
	void Log::Error(const char * msg)
	{
		std::cout << "[Error]:" << msg << std::endl;
	}
}