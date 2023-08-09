#pragma once

#include <memory>
#include "Log.h"

#ifdef MCORE_DEBUG
	#define MCORE_ENABLE_ASSERTS

 #if defined(MCORE_PLATFORM_WINDOWS)
    #define MT_DEBUGBREAK() __debugbreak()

 #else
    #include <signal.h>
    #define HZ_DEBUGBREAK() raise(SIGTRAP)
 #endif

#endif

#ifdef MCORE_ENABLE_ASSERTS

    #define MT_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro

	#define MCORE_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); MT_DEBUGBREAK(); } }

    #define MCORE_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed"); MT_DEBUGBREAK(); } }
 
#else
	#define MCORE_ASSERT(...)
#endif

#define BIT(x) (1 << x)

#define MCORE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)