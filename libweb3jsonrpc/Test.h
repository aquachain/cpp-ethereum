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
/** @file Test.h
 * @authors:
 *   Dimitry Khokhlov <dimitry@aquadev.com>
 * @date 2016
 */

#pragma once
#include "TestFace.h"

namespace dev
{

namespace aqua
{
class Client;
}

namespace rpc
{

class Test: public TestFace
{
public:
	Test(aqua::Client& _aqua);
	virtual RPCModules implementedModules() const override
	{
		return RPCModules{RPCModule{"test", "1.0"}};
	}

	virtual bool test_setChainParams(const Json::Value &param1) override;
	virtual bool test_mineBlocks(int _number) override;
	virtual bool test_modifyTimestamp(int _timestamp) override;
	virtual bool test_addBlock(std::string const& _rlp) override;
	virtual bool test_rewindToBlock(int _number) override;

private:
	aqua::Client& m_aqua;
};

}
}
