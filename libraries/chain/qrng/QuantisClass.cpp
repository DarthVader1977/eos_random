#include "eosio/chain/qrng/Quantis.h"

class QuantisClass
{
public:
    static double get_random_double(double minValue,double maxValue)
    {
        double rndDouble;
        QuantisReadScaledDouble(QUANTIS_DEVICE_USB,0,&rndDouble,minValue,maxValue);
        return rndDouble;
    }
    static double get_random_int(double minValue,double maxValue)
    {
        int rndInt;
        QuantisReadScaledInt(QUANTIS_DEVICE_USB,0,&rndInt,minValue,maxValue);
        return rndInt;
    }

};
