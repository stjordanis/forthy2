#include "forthy2/cx.hpp"
#include "forthy2/types/sym.hpp"

namespace forthy2 {
  Type &SymVal::get_type(Cx &cx) { return cx.sym_val; }

  void SymVal::sweep(Cx &cx) {
    Val::sweep(cx);
    cx.sym_val.pool.put(this);
  }
}
