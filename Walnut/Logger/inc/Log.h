#pragma once
#include "Core.h"
#include <string>
#include <iostream>

#ifdef  WL_PLATFORM_WINDOWS
	#include <Windows.h>
#endif //  WL_PLATFORM_WINDOWS



namespace Walnut {

	class WALNUT_API Log
	{
	private:
		Log();
		~Log();
		static Log* m_Instance;

	public:
		static void Trace(const char* msg);
		static void Warning(const char* msg);
		static void Error(const char* msg);

		inline static Log* getInstance() {
			if (m_Instance == nullptr)
				m_Instance = new Log();
			return m_Instance;
		}

	};
}


#define WL_CORE_TRACE(...)		::Walnut::Log::getInstance()->Trace(__VA_ARGS__)
#define WL_CORE_WARNING(...)    ::Walnut::Log::getInstance()->Warning(__VA_ARGS__)
#define WL_CORE_ERROR(...)		::Walnut::Log::getInstance()->Error(__VA_ARGS__)
