#include "Kewl/Util/Random.hpp"

namespace Kewl {

	std::mt19937 Random::s_RandomEngine;
	std::uniform_int_distribution<std::mt19937::result_type> Random::s_Distribution;

	std::mt19937_64 Random::s_RandomEngine64;
	std::uniform_int_distribution<std::mt19937_64::result_type> Random::s_Distribution64;

	uint64_t thread_local Random::s_SplitMix64Seed;

} // namespace Kewl