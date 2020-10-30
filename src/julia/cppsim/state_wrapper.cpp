#include <jlcxx/jlcxx.hpp>
#include "cppsim/state.hpp"

namespace jlcxx
{
    template<> struct SuperType<QuantumStateCpu> { typedef QuantumStateBase type; };
}

JLCXX_MODULE define_types_module(jlcxx::Module& quantum_state_types)
{
      quantum_state_types.add_type<QuantumStateCpu>("QuantumStateCpu", jlcxx::julia_base_type<QuantumStateBase>())
          .constructor<UINT>();
}
