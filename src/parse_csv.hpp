/*******************************************************************************
 * Copyright (c) 2017 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the MIT License
 *******************************************************************************
 *
 * Filename: parse_csv.hpp
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
 * 2017-01-09   wm              Initial version
 *
 ******************************************************************************/

#ifndef SRC_PARSE_CSV_HPP_
#define SRC_PARSE_CSV_HPP_

#include <vector>
#include <cstddef>

bool parse_csv(const char * first, std::size_t sz, std::vector<float> & v);

#endif /* SRC_PARSE_CSV_HPP_ */
