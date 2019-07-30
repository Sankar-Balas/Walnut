#pragma once

#include "Log.h"
#include <string>
#include <iostream>
#include <Windows.h>

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
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdout,
			FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		std::cout << "[Trace]:" << msg << std::endl;
	}
	void Log::Warning(const char * msg)
	{
		std::cout << "[Warning]:" << msg << std::endl;
	}
	void Log::Error(const char * msg)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdout,
			FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "[Error]:" << msg << std::endl;
	}

	inline std::ostream& red(std::ostream &s)
	{		
		return s;
	}
}