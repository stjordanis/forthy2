#ifndef FORTHY2_OP_HPP
#define FORTHY2_OP_HPP

#include <iostream>

#include "forthy2/form.hpp"
#include "forthy2/node.hpp"

namespace forthy2 {
  using namespace std;

  struct Cx;
  
  struct Op: Node<Op> {
    Form &form;
    
    Op(Form &form, Node<Op> &prev): form(form.ref()) { prev.append(*this); }
    virtual ~Op() {}
    
    virtual void dealloc(Cx &cx) {
      form.deref(cx);
      Node<Op>::unlink();
    }
    
    virtual void dump(ostream &out) = 0;
    virtual Node<Op> &eval(Cx &cx) { return *Node<Op>::next; }
    virtual void mark_vals(Cx &cx) { form.mark_vals(cx); } 
  };
}

#endif
