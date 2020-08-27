#pragma once

#ifdef NG_PLATEFORM_WINDOWS
	#ifdef NG_BUILD_DLL
		#define	ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif // HZ_BUILD_DLL
#endif // HZ_PLATEFORM_WINDOWS
