#pragma once
#include "Walnut"


namespace Walnut {

	class WALNUT_API  Log
	{
	private:
		Log();
		~Log();
		Log* m_Instance;
		LogLevel m_Level;
	public:
		static void setLogLevel(LogLevel lvl);
		static Log* GetLogInstance();
		Trace(const char* msg);
		Warning(const char* msg);
		Error(const char* msg);
	};
static Log* Log::m_Instance = nullptr;
}

#define WL_CORE_TRACE(...)		::Walnut::Log::GetLogInstance()->Trace(__VA_ARGS__)
#define WL_CORE_WARNING(...)    ::Walnut::Log::GetLogInstance()->Warning(__VA_ARGS__)
#define WL_CORE_ERROR(...)		::Walnut::Log::GetLogInstance()->Error(__VA_ARGS__)
