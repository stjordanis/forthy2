#include "forthy2/cx.hpp"
#include "forthy2/forms/scope.hpp"

namespace forthy2 {
  ScopeForm::ScopeForm(Pos pos): Form(pos) {}

  Node<Op> &ScopeForm::compile(Cx &cx, Forms &in, Node<Op> &out, int quote) {    
    if (quote > 0) {
      Node<Op> ops, *pc(&ops);
      Scope scope(cx, *cx.scope);
      cx.with_scope<void>(scope, [&]() { pc = &cx.compile(body, *pc, quote); });

      Stack stack;
      cx.with_stack<void>(stack, [&]() { cx.eval(ops, ops); });
      cx.dealloc(ops);
      
      ScopeForm &s(cx.scope_form.get(pos));
      cx.marked.push(s);
      for (Val *v: stack.items) { s.body.push_back(&v->unquote(cx, pos)); }
      return cx.push_op.get(s, out, s);
    }
    
    Node<Op> *pc(&out);
    Scope scope(cx, *cx.scope);
    cx.with_scope<void>(scope, [&]() { pc = &cx.compile(body, *pc); });
    return *pc;
  }

  Node<Op> &ScopeForm::compile_ref(Cx &cx, Forms &in, Node<Op> &out) {
    Lambda &l(cx.lambda_type.get(cx));
    Scope scope(cx, *cx.scope);
    
    cx.with_scope<void>(scope, [&]() {
        Node<Op> &pc(compile(cx, in, *l.ops.prev, 0));
        cx.return_op.get(*this, pc);
      });
    
    return cx.push_op.get(*this, out, l);
  }

  void ScopeForm::dealloc(Cx &cx) {
    for (Form *f: body) { f->deref(cx); }
    cx.scope_form.put(*this);
  }

  void ScopeForm::mark_vals(Cx &cx) {
    for (Form *f: body) { f->mark_vals(cx); }
  }

  void ScopeForm::write(ostream &out) { out << '{' << body << '}'; }
}
