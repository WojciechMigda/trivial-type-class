/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT license
 *******************************************************************************
 *
 * Filename: TrivialTypeClass.hpp
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
 * 2013-11-21   wm              Initial version
 *
 ******************************************************************************/


#ifndef TRIVIALTYPECLASS_HPP_
#define TRIVIALTYPECLASS_HPP_

#include "StaticStringHash.hpp"
#include <type_traits>

template<typename _Tp, unsigned long long _uniqId>
class basic_type
{
public:
    typedef _Tp type;
    static_assert(std::is_trivial<_Tp>::value == true, "template argument must be a trivial type");

    constexpr basic_type() = default;
    constexpr basic_type(const type & value) : m_value(value){}
    operator type &(){return m_value;}
private:
    type    m_value;
};

#define TRIVIAL_TYPE(type, name) typedef basic_type<type, (unsigned long long)(#name##_hash)> name

#endif /* TRIVIALTYPECLASS_HPP_ */
