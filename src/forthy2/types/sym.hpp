#ifndef FORTHY2_TYPE_SYM_HPP
#define FORTHY2_TYPE_SYM_HPP

#include "forthy2/pool_type.hpp"
#include "forthy2/prim_val.hpp"

namespace forthy2 {
  struct Sym;
  
  struct SymVal: PrimVal<const Sym *> {
    SymVal(const Sym *val): PrimVal<const Sym *>(val) {}
    void dump(ostream &out) override { out << val->name; }
    Type &get_type(Cx &cx) override;
    void sweep(Cx &cx) override;
  };
}

#endif
