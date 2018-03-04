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

#include "Instruction.h"
#include <map>

namespace dev
{
namespace aqua
{

static const std::map<Instruction,  InstructionInfo> c_instructionInfo =
{ //                                               Add,  Args,  Ret,  GasPriceTier
	{ Instruction::STOP,         { "STOP",           0,     0,    0,  Tier::Zero } },
	{ Instruction::ADD,          { "ADD",            0,     2,    1,  Tier::VeryLow } },
	{ Instruction::SUB,          { "SUB",            0,     2,    1,  Tier::VeryLow } },
	{ Instruction::MUL,          { "MUL",            0,     2,    1,  Tier::Low } },
	{ Instruction::DIV,          { "DIV",            0,     2,    1,  Tier::Low } },
	{ Instruction::SDIV,         { "SDIV",           0,     2,    1,  Tier::Low } },
	{ Instruction::MOD,          { "MOD",            0,     2,    1,  Tier::Low } },
	{ Instruction::SMOD,         { "SMOD",           0,     2,    1,  Tier::Low } },
	{ Instruction::EXP,          { "EXP",            0,     2,    1,  Tier::Special } },
	{ Instruction::NOT,          { "NOT",            0,     1,    1,  Tier::VeryLow } },
	{ Instruction::LT,           { "LT",             0,     2,    1,  Tier::VeryLow } },
	{ Instruction::GT,           { "GT",             0,     2,    1,  Tier::VeryLow } },
	{ Instruction::SLT,          { "SLT",            0,     2,    1,  Tier::VeryLow } },
	{ Instruction::SGT,          { "SGT",            0,     2,    1,  Tier::VeryLow } },
	{ Instruction::EQ,           { "EQ",             0,     2,    1,  Tier::VeryLow } },
	{ Instruction::ISZERO,       { "ISZERO",         0,     1,    1,  Tier::VeryLow } },
	{ Instruction::AND,          { "AND",            0,     2,    1,  Tier::VeryLow } },
	{ Instruction::OR,           { "OR",             0,     2,    1,  Tier::VeryLow } },
	{ Instruction::XOR,          { "XOR",            0,     2,    1,  Tier::VeryLow } },
	{ Instruction::BYTE,         { "BYTE",           0,     2,    1,  Tier::VeryLow } },
	{ Instruction::SHL,          { "SHL",            0,     2,    1,  Tier::VeryLow } },
	{ Instruction::SHR,          { "SHR",            0,     2,    1,  Tier::VeryLow } },
	{ Instruction::SAR,          { "SAR",            0,     2,    1,  Tier::VeryLow } },
	{ Instruction::ADDMOD,       { "ADDMOD",         0,     3,    1,  Tier::Mid } },
	{ Instruction::MULMOD,       { "MULMOD",         0,     3,    1,  Tier::Mid } },
	{ Instruction::SIGNEXTEND,   { "SIGNEXTEND",     0,     2,    1,  Tier::Low } },
	{ Instruction::SHA3,         { "SHA3",           0,     2,    1,  Tier::Special } },
	{ Instruction::ADDRESS,      { "ADDRESS",        0,     0,    1,  Tier::Base } },
	{ Instruction::BALANCE,      { "BALANCE",        0,     1,    1,  Tier::Special } },
	{ Instruction::ORIGIN,       { "ORIGIN",         0,     0,    1,  Tier::Base } },
	{ Instruction::CALLER,       { "CALLER",         0,     0,    1,  Tier::Base } },
	{ Instruction::CALLVALUE,    { "CALLVALUE",      0,     0,    1,  Tier::Base } },
	{ Instruction::CALLDATALOAD, { "CALLDATALOAD",   0,     1,    1,  Tier::VeryLow } },
	{ Instruction::CALLDATASIZE, { "CALLDATASIZE",   0,     0,    1,  Tier::Base } },
	{ Instruction::CALLDATACOPY, { "CALLDATACOPY",   0,     3,    0,  Tier::VeryLow } },
	{ Instruction::CODESIZE,     { "CODESIZE",       0,     0,    1,  Tier::Base } },
	{ Instruction::CODECOPY,     { "CODECOPY",       0,     3,    0,  Tier::VeryLow } },
	{ Instruction::GASPRICE,     { "GASPRICE",       0,     0,    1,  Tier::Base } },
	{ Instruction::EXTCODESIZE,  { "EXTCODESIZE",    0,     1,    1,  Tier::Special } },
	{ Instruction::EXTCODECOPY,  { "EXTCODECOPY",    0,     4,    0,  Tier::Special } },
	{ Instruction::RETURNDATASIZE,{"RETURNDATASIZE", 0,     0,    1,  Tier::Base } },
	{ Instruction::RETURNDATACOPY,{"RETURNDATACOPY", 0,     3,    0,  Tier::VeryLow } },
	{ Instruction::BLOCKHASH,    { "BLOCKHASH",      0,     1,    1,  Tier::Special } },
	{ Instruction::COINBASE,     { "COINBASE",       0,     0,    1,  Tier::Base } },
	{ Instruction::TIMESTAMP,    { "TIMESTAMP",      0,     0,    1,  Tier::Base } },
	{ Instruction::NUMBER,       { "NUMBER",         0,     0,    1,  Tier::Base } },
	{ Instruction::DIFFICULTY,   { "DIFFICULTY",     0,     0,    1,  Tier::Base } },
	{ Instruction::GASLIMIT,     { "GASLIMIT",       0,     0,    1,  Tier::Base } },
	{ Instruction::POP,          { "POP",            0,     1,    0,  Tier::Base } },
	{ Instruction::MLOAD,        { "MLOAD",          0,     1,    1,  Tier::VeryLow } },
	{ Instruction::MSTORE,       { "MSTORE",         0,     2,    0,  Tier::VeryLow } },
	{ Instruction::MSTORE8,      { "MSTORE8",        0,     2,    0,  Tier::VeryLow } },
	{ Instruction::SLOAD,        { "SLOAD",          0,     1,    1,  Tier::Special } },
	{ Instruction::SSTORE,       { "SSTORE",         0,     2,    0,  Tier::Special } },
	{ Instruction::JUMP,         { "JUMP",           0,     1,    0,  Tier::Mid } },
	{ Instruction::JUMPI,        { "JUMPI",          0,     2,    0,  Tier::High } },
	{ Instruction::PC,           { "PC",             0,     0,    1,  Tier::Base } },
	{ Instruction::MSIZE,        { "MSIZE",          0,     0,    1,  Tier::Base } },
	{ Instruction::GAS,          { "GAS",            0,     0,    1,  Tier::Base } },
	{ Instruction::JUMPDEST,     { "JUMPDEST",       0,     0,    0,  Tier::Special } },
	{ Instruction::PUSH1,        { "PUSH1",          1,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH2,        { "PUSH2",          2,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH3,        { "PUSH3",          3,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH4,        { "PUSH4",          4,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH5,        { "PUSH5",          5,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH6,        { "PUSH6",          6,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH7,        { "PUSH7",          7,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH8,        { "PUSH8",          8,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH9,        { "PUSH9",          9,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH10,       { "PUSH10",        10,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH11,       { "PUSH11",        11,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH12,       { "PUSH12",        12,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH13,       { "PUSH13",        13,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH14,       { "PUSH14",        14,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH15,       { "PUSH15",        15,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH16,       { "PUSH16",        16,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH17,       { "PUSH17",        17,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH18,       { "PUSH18",        18,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH19,       { "PUSH19",        19,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH20,       { "PUSH20",        20,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH21,       { "PUSH21",        21,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH22,       { "PUSH22",        22,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH23,       { "PUSH23",        23,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH24,       { "PUSH24",        24,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH25,       { "PUSH25",        25,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH26,       { "PUSH26",        26,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH27,       { "PUSH27",        27,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH28,       { "PUSH28",        28,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH29,       { "PUSH29",        29,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH30,       { "PUSH30",        30,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH31,       { "PUSH31",        31,     0,    1,  Tier::VeryLow } },
	{ Instruction::PUSH32,       { "PUSH32",        32,     0,    1,  Tier::VeryLow } },
	{ Instruction::DUP1,         { "DUP1",           0,     1,    2,  Tier::VeryLow } },
	{ Instruction::DUP2,         { "DUP2",           0,     2,    3,  Tier::VeryLow } },
	{ Instruction::DUP3,         { "DUP3",           0,     3,    4,  Tier::VeryLow } },
	{ Instruction::DUP4,         { "DUP4",           0,     4,    5,  Tier::VeryLow } },
	{ Instruction::DUP5,         { "DUP5",           0,     5,    6,  Tier::VeryLow } },
	{ Instruction::DUP6,         { "DUP6",           0,     6,    7,  Tier::VeryLow } },
	{ Instruction::DUP7,         { "DUP7",           0,     7,    8,  Tier::VeryLow } },
	{ Instruction::DUP8,         { "DUP8",           0,     8,    9,  Tier::VeryLow } },
	{ Instruction::DUP9,         { "DUP9",           0,     9,   10,  Tier::VeryLow } },
	{ Instruction::DUP10,        { "DUP10",          0,    10,   11,  Tier::VeryLow } },
	{ Instruction::DUP11,        { "DUP11",          0,    11,   12,  Tier::VeryLow } },
	{ Instruction::DUP12,        { "DUP12",          0,    12,   13,  Tier::VeryLow } },
	{ Instruction::DUP13,        { "DUP13",          0,    13,   14,  Tier::VeryLow } },
	{ Instruction::DUP14,        { "DUP14",          0,    14,   15,  Tier::VeryLow } },
	{ Instruction::DUP15,        { "DUP15",          0,    15,   16,  Tier::VeryLow } },
	{ Instruction::DUP16,        { "DUP16",          0,    16,   17,  Tier::VeryLow } },
	{ Instruction::SWAP1,        { "SWAP1",          0,     2,    2,  Tier::VeryLow } },
	{ Instruction::SWAP2,        { "SWAP2",          0,     3,    3,  Tier::VeryLow } },
	{ Instruction::SWAP3,        { "SWAP3",          0,     4,    4,  Tier::VeryLow } },
	{ Instruction::SWAP4,        { "SWAP4",          0,     5,    5,  Tier::VeryLow } },
	{ Instruction::SWAP5,        { "SWAP5",          0,     6,    6,  Tier::VeryLow } },
	{ Instruction::SWAP6,        { "SWAP6",          0,     7,    7,  Tier::VeryLow } },
	{ Instruction::SWAP7,        { "SWAP7",          0,     8,    8,  Tier::VeryLow } },
	{ Instruction::SWAP8,        { "SWAP8",          0,     9,    9,  Tier::VeryLow } },
	{ Instruction::SWAP9,        { "SWAP9",          0,    10,   10,  Tier::VeryLow } },
	{ Instruction::SWAP10,       { "SWAP10",         0,    11,   11,  Tier::VeryLow } },
	{ Instruction::SWAP11,       { "SWAP11",         0,    12,   12,  Tier::VeryLow } },
	{ Instruction::SWAP12,       { "SWAP12",         0,    13,   13,  Tier::VeryLow } },
	{ Instruction::SWAP13,       { "SWAP13",         0,    14,   14,  Tier::VeryLow } },
	{ Instruction::SWAP14,       { "SWAP14",         0,    15,   15,  Tier::VeryLow } },
	{ Instruction::SWAP15,       { "SWAP15",         0,    16,   16,  Tier::VeryLow } },
	{ Instruction::SWAP16,       { "SWAP16",         0,    17,   17,  Tier::VeryLow } },
	{ Instruction::LOG0,         { "LOG0",           0,     2,    0,  Tier::Special } },
	{ Instruction::LOG1,         { "LOG1",           0,     3,    0,  Tier::Special } },
	{ Instruction::LOG2,         { "LOG2",           0,     4,    0,  Tier::Special } },
	{ Instruction::LOG3,         { "LOG3",           0,     5,    0,  Tier::Special } },
	{ Instruction::LOG4,         { "LOG4",           0,     6,    0,  Tier::Special } },

	{ Instruction::JUMPTO,       { "JUMPTO",         2,     1,    0,  Tier::VeryLow } },
	{ Instruction::JUMPIF,       { "JUMPIF",         2,     2,    0,  Tier::Low } },
	{ Instruction::JUMPV,        { "JUMPV",          2,     1,    0,  Tier::Mid } },
	{ Instruction::JUMPSUB,      { "JUMPSUB",        2,     1,    0,  Tier::Low } },
	{ Instruction::JUMPSUBV,     { "JUMPSUBV",       2,     1,    0,  Tier::Mid } },
	{ Instruction::BEGINSUB,     { "BEGINSUB",       0,     0,    0,  Tier::Special } },
	{ Instruction::BEGINDATA,    { "BEGINDATA",      0,     0,    0,  Tier::Special } },
	{ Instruction::RETURNSUB,    { "RETURNSUB",      0,     1,    0,  Tier::Mid } },
	{ Instruction::PUTLOCAL,     { "PUTLOCAL",       2,     1,    0,  Tier::VeryLow } },
	{ Instruction::GETLOCAL,     { "GETLOCAL",       2,     0,    1,  Tier::VeryLow } },

	{ Instruction::XADD,         { "XADD",           1,     0,    0,  Tier::Special } },
	{ Instruction::XMUL,         { "XMUL",           1,     2,    1,  Tier::Special } },
	{ Instruction::XSUB,         { "XSUB",           1,     2,    1,  Tier::Special } },
	{ Instruction::XDIV,         { "XDIV",           1,     2,    1,  Tier::Special } },
	{ Instruction::XSDIV,        { "XSDIV",          1,     2,    1,  Tier::Special } },
	{ Instruction::XMOD,         { "XMOD",           1,     2,    1,  Tier::Special } },
	{ Instruction::XSMOD,        { "XSMOD",          1,     2,    1,  Tier::Special } },
	{ Instruction::XLT,          { "XLT",            1,     2,    1,  Tier::Special } },
	{ Instruction::XGT,          { "XGT",            1,     2,    1,  Tier::Special } },
	{ Instruction::XSLT,         { "XSLT",           1,     2,    1,  Tier::Special } },
	{ Instruction::XSGT,         { "XSGT",           1,     2,    1,  Tier::Special } },
	{ Instruction::XEQ,          { "XEQ",            1,     2,    1,  Tier::Special } },
	{ Instruction::XISZERO,      { "XISZERO",        1,     2,    1,  Tier::Special } },
	{ Instruction::XAND,         { "XAND",           1,     1,    1,  Tier::Special } },
	{ Instruction::XOR,          { "XOR",            1,     2,    1,  Tier::Special } },
	{ Instruction::XXOR,         { "XXOR",           1,     2,    1,  Tier::Special } },
	{ Instruction::XNOT,         { "XNOT",           1,     2,    1,  Tier::Special } },
	{ Instruction::XSHL,         { "XSHL",           1,     2,    1,  Tier::Special } },
	{ Instruction::XSHR,         { "XSHR",           1,     2,    1,  Tier::Special } },
	{ Instruction::XSAR,         { "XSAR",           1,     2,    1,  Tier::Special } },
	{ Instruction::XROL,         { "XROL",           1,     2,    1,  Tier::Special } },
	{ Instruction::XROR,         { "XROR",           1,     2,    1,  Tier::Special } },
	{ Instruction::XPUSH,        { "XPUSH",          1,     1,    1,  Tier::VeryLow } },
	{ Instruction::XMLOAD,       { "XMLOAD",         1,     1,    1,  Tier::VeryLow } },
	{ Instruction::XMSTORE,      { "XMSTORE",        1,     2,    0,  Tier::VeryLow } },
	{ Instruction::XSLOAD,       { "XSLOAD",         1,     1,    1,  Tier::Special } },
	{ Instruction::XSSTORE,      { "XSSTORE",        1,     2,    0,  Tier::Special } },
	{ Instruction::XVTOWIDE,     { "XVTOWIDE",       1,     1,    1,  Tier::VeryLow } },
	{ Instruction::XWIDETOV,     { "XWIDETOV",       1,     1,    1,  Tier::VeryLow } },
	{ Instruction::XPUT,         { "XPUT",           1,     3,    1,  Tier::Special } },
	{ Instruction::XGET,         { "XGET",           1,     2,    1,  Tier::Special } },
	{ Instruction::XSWIZZLE,     { "XSWIZZLE",       1,     2,    1,  Tier::Special } },
	{ Instruction::XSHUFFLE,     { "XSHUFFLE",       1,     3,    1,  Tier::Special } },
	{ Instruction::CREATE,       { "CREATE",         0,     3,    1,  Tier::Special } },
	{ Instruction::CREATE2,      { "CREATE2",        0,     4,    1,  Tier::Special } },
	{ Instruction::CALL,         { "CALL",           0,     7,    1,  Tier::Special } },
	{ Instruction::CALLCODE,     { "CALLCODE",       0,     7,    1,  Tier::Special } },
	{ Instruction::RETURN,       { "RETURN",         0,     2,    0,  Tier::Zero } },
	{ Instruction::STATICCALL,   { "STATICCALL",     0,     6,    1,  Tier::Special } },
	{ Instruction::DELEGATECALL, { "DELEGATECALL",   0,     6,    1,  Tier::Special } },
	{ Instruction::REVERT,       { "REVERT",         0,     2,    0,  Tier::Special } },
	{ Instruction::INVALID,      { "INVALID",        0,     0,    0,  Tier::Zero    } },
	{ Instruction::SUICIDE,      { "SUICIDE",        0,     1,    0,  Tier::Special } },
 
	// these are generated by the interpreter - should never be in user code
	{ Instruction::PUSHC,        { "PUSHC",          3,     0,    1, Tier::VeryLow } },
	{ Instruction::JUMPC,        { "JUMPC",          0,     1,    0, Tier::Mid } },
	{ Instruction::JUMPCI,       { "JUMPCI",         0,     2,    0, Tier::High } },
}; 
 
InstructionInfo instructionInfo(Instruction _inst)
{
	auto it = c_instructionInfo.find(_inst);
	if (it != c_instructionInfo.end())
		return it->second;
	return InstructionInfo{{}, 0, 0, 0, Tier::Invalid};
}


}
}