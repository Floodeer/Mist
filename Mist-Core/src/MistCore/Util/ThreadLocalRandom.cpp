#include "glpch.h"

#include "ThreadlocalRandom.h"

namespace Mist {

	thread_local std::mt19937 ThreadLocalRandom::s_TwisterEngine;
	std::uniform_int_distribution<std::mt19937::result_type> ThreadLocalRandom::s_Distribution;

}