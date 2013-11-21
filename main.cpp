/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT license
 *******************************************************************************
 *
 * Filename: main.cpp
 *
 * Description:
 *      description
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2013-11-20   wm              Initial version
 *
 ******************************************************************************/

#ifdef __GNUC__
    #if __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 7)
        #error Your GCC compiler version does not support operator"" yet.
    #endif
#endif

#include "TrivialTypeClass.hpp"
#include <iostream>

TRIVIAL_TYPE(int, Foo);

static_assert(std::is_pod<Foo>::value == true, "");
static_assert(std::is_destructible<Foo>::value == true, "");
static_assert(std::is_constructible<Foo>::value == true, "");
static_assert(std::is_default_constructible<Foo>::value == true, "");
static_assert(std::is_copy_constructible<Foo>::value == true, "");
static_assert(std::is_move_constructible<Foo>::value == true, "");
static_assert(std::is_assignable<Foo, int>::value == true, "");
static_assert(std::is_copy_assignable<Foo>::value == true, "");
static_assert(std::is_move_assignable<Foo>::value == true, "");

TRIVIAL_TYPE(int, Bar);

static_assert(std::is_assignable<Foo, Bar>::value == false, "");

enum Enum
{
    First,
    Second,
    Third,
};

TRIVIAL_TYPE(Enum, Baz);

static_assert(std::is_pod<Baz>::value == true, "");
static_assert(std::is_destructible<Baz>::value == true, "");
static_assert(std::is_constructible<Baz>::value == true, "");
static_assert(std::is_default_constructible<Baz>::value == true, "");
static_assert(std::is_copy_constructible<Baz>::value == true, "");
static_assert(std::is_move_constructible<Baz>::value == true, "");
static_assert(std::is_assignable<Baz, Enum>::value == true, "");
static_assert(std::is_copy_assignable<Baz>::value == true, "");
static_assert(std::is_move_assignable<Baz>::value == true, "");

int main()
{
    Foo     foo1;
    Foo     foo2(47);
    Foo     foo3 = foo2;
    Foo     foo4(foo2);
    Foo     foo6 = 19;
    int     baz = foo6;
    Foo     foo5{baz};
    Foo     foo7{foo6};
    foo6 += 5;
    foo3++;

    std::cout
    << foo2 << ", "
    << foo3 << ", "
    << foo4 << ", "
    << foo5 << ", "
    << foo6 << ", "
    << foo7 << std::endl;

    return 0;
}

// conversions
int fn(Foo & foo)
{
    return foo;
}

int cfn(const Foo & foo)
{
    return foo;
}
