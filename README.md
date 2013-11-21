trivial-type-class
================

trivial type class wrapper.

It allows you to create trivial type-like classes which give you complete type control,
in contrast to regular typedef's. For instance, instead of:

  typedef int first_int_t;
  typedef int other_int_t;

which doesn't prohibit you from:

  first_int_t     first = 0;
  other_int_t     other = first; // this is allowed, not what I want

with this code you can do the following:

  TRIVIAL_TYPE(int, FirstInt);
  TRIVIAL_TYPE(int, OtherInt);

  Firstint    first = 0;
  OtherInt    other = first; // BAD - this won't compile, good!

and still you can use FirstInt and OtherInt just as if they were regular integers.

Under the hood the TRIVIAL_TYPE macro expands to a typedef of a templated
envelope class to a requested type:

  #define TRIVIAL_TYPE(type, name) typedef TrivialType<type, (unsigned long long)(#name##_hash)> name

where:

  template<typename _Tp, unsigned long long _uniqId>
  class TrivialType;

Second template argument to TrivialType is a 64-bit hash generated in compile time from
the 'name' parameter passed to the TRIVIAL_TYPE macro.
