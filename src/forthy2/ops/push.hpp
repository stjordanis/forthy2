#ifndef FORTHY2_OP_PUSH_HPP
#define FORTHY2_OP_PUSH_HPP

#include "forthy2/op.hpp"

namespace forthy2 {
  struct Val;
  
  struct PushOp: Op {
    Val &val;
    
    PushOp(Form &form, Node<Op> &prev, Val &val);
    void dealloc(Cx &cx) override;
    void dump(ostream &out) override;
    Node<Op> &eval(Cx &cx) override;
    void mark_vals(Cx &cx) override; 
  };
}

#endif
