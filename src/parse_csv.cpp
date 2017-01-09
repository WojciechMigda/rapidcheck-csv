/*******************************************************************************
 * Copyright (c) 2017 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: parse_csv.cpp
 *
 * Description:
 *      Simple numeric CSV parser with Spirit::Qi
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2017-01-09   wm              Initial version
 *
 ******************************************************************************/

#include "boost/spirit/include/qi.hpp"

#include <vector>
#include <cstddef>
#include <cmath>

bool parse_csv(const char * first, std::size_t sz, std::vector<float> & v)
{
    using namespace boost::spirit;

    const char * last = first + sz;

    bool ok = qi::phrase_parse(
         first, last,
         (
             double_[([&v](float x){ v.push_back(x); })]
             | eps[([&v](){ v.push_back(NAN); })]
         ) % ',',
         qi::ascii::space
     );

    return ok;
}
