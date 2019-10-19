#include "forthy2/cx.hpp"
#include "forthy2/forms/lit.hpp"

namespace forthy2 {
  LitForm::LitForm(Pos pos, Val &val): Form(pos), val(val) {}

  Node<Op> &LitForm::compile(Cx &cx, Forms &in, Node<Op> &out) {
    if (cte) {
      cx.push(val);
      return out;
    }
    
    return cx.push_op.get(*this, out, val);
  }

  void LitForm::dealloc(Cx &cx) { cx.lit_form.put(*this); }

  void LitForm::dump(ostream &out) { val.dump(out); }
  
  void LitForm::mark_vals(Cx &cx) { val.mark(cx); }
}
