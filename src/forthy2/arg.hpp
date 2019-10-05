#ifndef FORTHY2_ARG_HPP
#define FORTHY2_ARG_HPP

#include <vector>

namespace forthy2 {
  using namespace std;

  struct Type;
  struct Val;
  
  struct Arg {
    Type *type = nullptr;
    Val *val = nullptr;

    Arg(Type &type): type(&type) {}
    Arg(Val *val): val(val) {}
  };
  
  using Args = vector<Arg>;
}

#endif
