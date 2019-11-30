#include "Quantis.h"

#include <tuple>
#include <string>

using namespace std;

class quantis_random
{
public:
    static tuple<bool, double, string> get_random_double(double min_value, double max_value) const
    {
        bool status = false;
        double rng_double = 0.0;
        string description;

        QuantisError code = QuantisReadScaledDouble(QUANTIS_DEVICE_USB, 0, &rngDouble, min_value, max_value);
        if (code == QuantisError::QUANTIS_SUCCESS) {
            status = true;
        } else {
            description = QuantisStrError(code);
        }

        return make_tuple(status, rng_double, description);
    }

    static tuple<bool, int32_t, string> get_random_int(int32_t min_value, int32_t max_value) const
    {
        bool status = false;
        int rng_int = 0;
        string description;

        QuantisError code = QuantisReadScaledInt(QUANTIS_DEVICE_USB, 0, &rng_int, min_value, max_value);
        if (code == QuantisError::QUANTIS_SUCCESS) {
            status = true;
        } else {
            description = QuantisStrError(code);
        }

        return make_tuple(status, rng_int, description);
    }

};
