/*
	This file is part of cpp-aquachain.

	cpp-aquachain is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-aquachain is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-aquachain.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file Exceptions.h
 * @author Christian <c@aquadev.com>
 * @date 2016
 */

#pragma once

#include <libdevcore/Exceptions.h>

namespace dev
{
namespace crypto
{

/// Rare malfunction of cryptographic functions.
DEV_SIMPLE_EXCEPTION(CryptoException);

}
}
