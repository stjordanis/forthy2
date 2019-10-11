#ifndef FORTHY2_BOOL_HPP
#define FORTHY2_BOOL_HPP

#include "forthy2/val.hpp"

namespace forthy2 {
  struct Bool: Val {
    using Imp = bool;
    Imp imp;

    Bool(Imp imp);
    operator bool() override { return imp; }
    Cmp cmp(Val &other) override;
    void dump(ostream &out) override;
    bool is(Val &other) override;
    void sweep(Cx &cx) override;
    Type &type(Cx &cx) override;
  };
}

#endif
