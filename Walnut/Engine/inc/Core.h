#pragma once

//Just to support Windows
#ifdef WL_PLATFORM_WINDOWS
	#if WL_DYNAMIC_LINK
		#if	WL_BUILD_DLL
			#define WALNUT_API __declspec(dllexport)
		#else
			#define WALNUT_API __declspec(dllimport)
		#endif
	#else
		#define WALNUT_API
	#endif
#else
	#error Walnut only supports Windows!
#endif


#define BIT(x) 1<<x