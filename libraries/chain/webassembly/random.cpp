#include <eosio/chain/webassembly/interface.hpp>
#include <stdlib.h>
#include <tuple>

#include <eosio/chain/quantis/QuantisRandom.hpp>

namespace eosio { namespace chain { namespace webassembly {

   int32_t interface::generate_random()
   {
       bool status_rng;
       int32_t rng_number;
       string description;
       std::tie(status_rng, rng_number, description) = quantis_random::get_test_random_int(-10000, 10000);
       EOS_ASSERT( status_rng, quantis_type_exception, description );

       return rng_number;
   }

}}} // ns eosio::chain::webassembly
