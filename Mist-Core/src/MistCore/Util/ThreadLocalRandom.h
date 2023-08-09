#pragma once

#include <random>

#include <glm/glm.hpp>

namespace Mist {

	class ThreadLocalRandom
	{
	public:
		static void Init()
		{
			s_TwisterEngine.seed(std::random_device()());
		}

		static uint32_t UInt()
		{
			return s_Distribution(s_TwisterEngine);
		}

		static uint32_t UInt(uint32_t min, uint32_t max)
		{
			return min + (s_Distribution(s_TwisterEngine) % (max - min + 1));
		}

		static float Float()
		{
			return (float)s_Distribution(s_TwisterEngine) / (float)std::numeric_limits<uint32_t>::max();
		}

		static glm::vec3 Vec3()
		{
			return glm::vec3(Float(), Float(), Float());
		}

		static glm::vec3 Vec3(float min, float max)
		{
			return glm::vec3(Float() * (max - min) + min, Float() * (max - min) + min, Float() * (max - min) + min);
		}

		static glm::vec3 InUnitSphere()
		{
			return glm::normalize(Vec3(-1.0f, 1.0f));
		}
	private:
		static thread_local std::mt19937 s_TwisterEngine;
		static std::uniform_int_distribution<std::mt19937::result_type> s_Distribution;
	};
}