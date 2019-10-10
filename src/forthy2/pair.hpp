#ifndef FORTHY2_PAIR_HPP
#define FORTHY2_PAIR_HPP

#include "forthy2/val.hpp"

namespace forthy2 {
  struct Pair: Val {
    using Imp = pair<Val *, Val *>;
    Imp imp;

    Pair(const Imp &imp);
    Pair(Val &first, Val &second);
    Cmp cmp(Val &other) override;
    void dump(ostream &out) override;
    Type &get_type(Cx &cx) override;
    bool is(Val &other) override;
    bool mark(Cx &cx) override;
    void sweep(Cx &cx) override;
  };
}

#endif