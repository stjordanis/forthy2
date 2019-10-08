#ifndef FORTHY2_FORM_LIT_HPP
#define FORTHY2_FORM_LIT_HPP

#include "forthy2/form.hpp"

namespace forthy2 {
  struct Val;
  
  struct LitForm: Form {
    Val &val;
    
    LitForm(const Pos &pos, Val &val);
    void dealloc(Cx &cx) override;
    void dump(ostream &out) override;
    void mark_vals(Cx &cx) override;
  };
}

#endif