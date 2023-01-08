#include "Helpers.h"

namespace Helpers
{
    size_t GetRandom(size_t Start, size_t End)
    {
        // Create a random number generator
        static std::random_device RandomDevice;
        static std::mt19937 MersenneGenerator(RandomDevice());
        std::uniform_int_distribution<size_t> UniformDistribution(Start, End);  // random hexadecimal digit

        return UniformDistribution(MersenneGenerator);
    }

    std::string GenerateGUID()
    {
        // Generate the GUID
        std::string GUID;

        auto PirOfFour = [&](const bool FirstTime, const int NumberOfSymbols)
        {
            if (FirstTime == false)
            {
                GUID += '-';
            }

            for (int i = 0; i < NumberOfSymbols; i++)
            {
                GUID += std::to_string(GetRandom(0, 15));
            }
        };

        PirOfFour(true, 8);
        PirOfFour(false, 4);
        PirOfFour(false, 4);
        PirOfFour(false, 4);
        PirOfFour(false, 12);

        return GUID;
    }
}