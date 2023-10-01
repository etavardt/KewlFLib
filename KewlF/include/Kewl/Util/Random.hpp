#pragma once

#include <random>

#include <glm/glm.hpp>

namespace Kewl
{
    class Random
    {
    public:

        static void Init()
        {
            s_RandomEngine.seed(std::random_device()());
        }

        static void Init64()
        {
            s_RandomEngine64.seed(std::random_device()());
        }

        static uint32_t Uint()
        {
            return s_Distribution(s_RandomEngine);
        }

        static uint64_t Uint64()
        {
            return s_Distribution64(s_RandomEngine64);
        }

        static uint32_t Uint(uint32_t min, uint32_t max)
        {
            return min + (s_Distribution(s_RandomEngine) % (max - min + 1));
        }

        static uint64_t Uint64(uint64_t min, uint64_t max)
        {
            return min + (s_Distribution64(s_RandomEngine64) % (max - min + 1));
        }

        static float RandFloat()
        {
            return (float)s_Distribution(s_RandomEngine) / (float)std::numeric_limits<uint32_t>::max();
        }

        static double RandDouble()
        {
            return (double)s_Distribution64(s_RandomEngine64) / (double)std::numeric_limits<uint64_t>::max();
        }

        static glm::vec3 Vec3()
        {
            return glm::vec3(RandFloat(), RandFloat(), RandFloat());
        }

        static glm::vec3 Vec3_64()
        {
            return glm::vec3(RandDouble(), RandDouble(), RandDouble());
        }

        static glm::vec3 Vec3(float min, float max)
        {
            float maxSubMin = max - min;
            return glm::vec3(
                RandFloat() * maxSubMin + min,
                RandFloat() * maxSubMin + min,
                RandFloat() * maxSubMin + min
            );
        }

        static glm::dvec3 Vec3_64(double min, double max)
        {
            double maxSubMin = max - min;
            return glm::dvec3(
                RandDouble() * maxSubMin + min,
                RandDouble() * maxSubMin + min,
                RandDouble() * maxSubMin + min
            );
        }

        static glm::dvec3 Vec3_SM64(double min, double max)
        {
            double maxSubMin = max - min;
            return glm::dvec3(
                SM64() * maxSubMin + min,
                SM64() * maxSubMin + min,
                SM64() * maxSubMin + min
            );
        }

        static glm::vec4 Vec4()
        {
            return glm::vec4(RandFloat(), RandFloat(), RandFloat(), RandFloat());
        }
        static glm::dvec4 Vec4_64()
        {
            return glm::dvec4(RandDouble(), RandDouble(), RandDouble(), RandDouble());
        }
        static glm::vec4 Vec4(float min, float max)
        {
            float maxSubMin = max - min;
            return glm::vec4(
                RandFloat() * maxSubMin + min,
                RandFloat() * maxSubMin + min,
                RandFloat() * maxSubMin + min,
                RandFloat() * maxSubMin + min
            );
        }
        static glm::dvec4 Vec4_64(double min, double max)
        {
            double maxSubMin = max - min;
            return glm::dvec4(
                RandDouble() * maxSubMin + min,
                RandDouble() * maxSubMin + min,
                RandDouble() * maxSubMin + min,
                RandDouble() * maxSubMin + min
            );
        }

        //What is this for???
        //inline static glm::vec3 inUnitSphere() {
        //    return glm::normalize( vec3( -1.0f, 1.0f ) );
        //}

        /*
            //typedef unsigned long long uint64_t;
            //typedef int uint64_t;
            This is a fixed-increment version of Java 8's SplittableRandom generator
            See http://dx.doi.org/10.1145/2714064.2660195 and
            http://docs.oracle.com/javase/8/docs/api/java/util/SplittableRandom.html

            It is a very fast generator passing BigCrush, and it can be useful if
            for some reason you absolutely want 64 bits of state; otherwise, we
            rather suggest to use a xoroshiro128+ (for moderately parallel
            computations) or xorshift1024* (for massively parallel computations)
            generator.
        */
        static uint64_t SplitMix64()
        {
            uint64_t z = (s_SplitMix64Seed += UINT64_C(0x9E3779B97F4A7C15));
            z = (z ^ (z >> 30)) * UINT64_C(0xBF58476D1CE4E5B9);
            z = (z ^ (z >> 27)) * UINT64_C(0x94D049BB133111EB);
            return z ^ (z >> 31);
        }

        static void SeedSplitMix64(uint64_t seed)
        {
            s_SplitMix64Seed = seed;
        }

        static double SM64(void)
        {
            return (double)SplitMix64() / (double)std::numeric_limits<uint64_t>::max();
        }

        static double SM64(double min, double max)
        {
            double maxSubMin = max - min;
            return SM64() * maxSubMin + min;
        }

        static void SeedXoshiro256p(uint64_t seed) {
            SeedSplitMix64(seed);

            uint64_t* s = s_ShuffleTable;

            s[0] = SplitMix64();
            s[1] = SplitMix64();
            s[2] = SplitMix64();
            s[3] = SplitMix64();
        }

        static uint64_t Xoshiro256p(void) {
            uint64_t* s = s_ShuffleTable;
            uint64_t const result = s[0] + s[3];
            uint64_t const t = s[1] << 17;

            s[2] ^= s[0];
            s[3] ^= s[1];
            s[1] ^= s[2];
            s[0] ^= s[3];

            s[2] ^= t;
            s[3] = rol64(s[3], 45);

            return result;
        }

        static double X256p64(void) {
            return (double)SplitMix64() / (double)std::numeric_limits<uint64_t>::max();
        }

        static double X256p64(double min, double max) {
            double maxSubMin = max - min;
            return X256p64() * maxSubMin + min;
        }

        static glm::dvec3 Vec3_X256p64(double min, double max) {
            double maxSubMin = max - min;
            return glm::dvec3(
                X256p64() * maxSubMin + min,
                X256p64() * maxSubMin + min,
                X256p64() * maxSubMin + min
            );
        }



    private:
        static std::mt19937 s_RandomEngine;
        static std::uniform_int_distribution<std::mt19937::result_type> s_Distribution;

        static std::mt19937_64 s_RandomEngine64;
        static std::uniform_int_distribution<std::mt19937_64::result_type> s_Distribution64;

        static thread_local uint64_t s_SplitMix64Seed; /* The state can be seeded with any value. */

        static thread_local uint64_t s_ShuffleTable[4];

        static uint64_t rol64(uint64_t x, int k) {
            return (x << k) | (x >> (64 - k));
        }


    };

} // namespace Kewl


