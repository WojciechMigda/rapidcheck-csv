/*******************************************************************************
 * Copyright (c) 2017 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: main.hpp
 *
 * Description:
 *      Playing with rapidcheck
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

#include "parse_csv.hpp"

#include "rapidcheck.h"

#include "boost/algorithm/string/join.hpp"

#include <string>
#include <cstddef>
#include <iostream>
#include <algorithm>

int main()
{
    rc::check("string is parsed into vector with correct number of elements",
        []()
        {
            auto g_vstr = rc::gen::container<std::vector<std::string>>(
                rc::gen::weightedOneOf<std::string>(
                    {
                        {6, rc::gen::map(rc::gen::arbitrary<float>(), [](float x){ return std::to_string(x); })},
                        {1, rc::gen::just(std::string())}
                    })
                );

            auto s = *rc::gen::map(g_vstr, [](std::vector<std::string> const & vstr) -> std::string
                {
                    return boost::algorithm::join(vstr, ",");
                });

            std::vector<float> v;
            auto nelem = std::count(s.cbegin(), s.cend(), ',') + 1;

            parse_csv(s.c_str(), s.size(), v);

            //RC_LOG() << s << std::endl;
            //std::cerr << s << '\n';

            RC_ASSERT(v.size() == nelem);
        });
}
