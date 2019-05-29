#include "Log.h"

namespace Walnut {

	Log::Log() {}
	Log::~Log() {}

	void Log::setLogLevel(LogLevel lvl)
	{
		m_Level = lvl;
	}
	Log* Log::GetLogInstance()
	{
		return nullptr;
	}
	static Log* GetLogInstance()
	{
		if (m_Instance == nullptr)
			m_Instance = new Log();

		return m_Instance;
	}
}