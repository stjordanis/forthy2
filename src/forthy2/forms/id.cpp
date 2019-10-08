#include "forthy2/cx.hpp"
#include "forthy2/forms/id.hpp"

namespace forthy2 {
  IdForm::IdForm(const Pos &pos, const Sym *val): Form(pos), val(val) {}

  Node<Op> &IdForm::compile(Cx &cx, FormIter &in, FormIter end, Node<Op> &out) {
    Val &v(cx.env->get(pos, val));
    Type *vt(&v.get_type(cx));

    if (vt == &cx.macro_val) {
      return dynamic_cast<MacroVal &>(v).val.expand(cx, *this, in, end, out);
    }
    
    return *cx.push_op.get(*this, out, v);
  }

  void IdForm::dealloc(Cx &cx) { cx.id_form.put(this); }

  void IdForm::dump(ostream &out) { out << "id " << val->name; }
}
