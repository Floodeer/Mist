#pragma once

#include <memory>

#ifdef MCORE_DEBUG
	#define MCORE_ENABLE_ASSERTS
#endif

#ifdef MCORE_ENABLE_ASSERTS
	#define MCORE_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MCORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define MCORE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)