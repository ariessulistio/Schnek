/*
 * arraycheck.hpp
 *
 * Created on: 23 Jan 2007
 * Author: Holger Schmitz
 * Email: holger@notjustphysics.com
 *
 * Copyright 2012 Holger Schmitz
 *
 * This file is part of Schnek.
 *
 * Schnek is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Schnek is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Schnek.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef SCHNEK_ARRAYCHECK_HPP_
#define SCHNEK_ARRAYCHECK_HPP_

#include <cassert>

namespace schnek {

/** Class to plug into the Array as CheckingPolicy.
 *  Performs no argument checking at all.
 */
template<int limit>
class ArrayNoArgCheck
{
  public:
    /** The check method does not do anything */
    void check(int) const {} 
};

/** Class to plug into the Array as CheckingPolicy.
 *  Performs no argument checking at all.
 */
template<int limit>
class ArrayAssertArgCheck
{
  public:
    /** The check method does not do anything */
    void check(int i) const {
      assert(i>=0);
      assert(i<limit);
    }
};

}

#endif // SCHNEK_ARGCHECK_HPP_
