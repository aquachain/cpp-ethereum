#pragma once
#include <libaquachain/Executive.h>
#include "DebugFace.h"

namespace dev
{

namespace aqua
{
class Client;

StandardTrace::DebugOptions debugOptions(Json::Value const& _json);
}

namespace rpc
{

class SessionManager;

class Debug: public DebugFace
{
public:
	explicit Debug(aqua::Client const& _aqua);

	virtual RPCModules implementedModules() const override
	{
		return RPCModules{RPCModule{"debug", "1.0"}};
	}


	virtual Json::Value debug_traceTransaction(std::string const& _txHash, Json::Value const& _json) override;
	virtual Json::Value debug_traceCall(Json::Value const& _call, std::string const& _blockNumber, Json::Value const& _options) override;
	virtual Json::Value debug_traceBlockByNumber(int _blockNumber, Json::Value const& _json) override;
	virtual Json::Value debug_traceBlockByHash(std::string const& _blockHash, Json::Value const& _json) override;
	virtual Json::Value debug_storageRangeAt(std::string const& _blockHashOrNumber, int _txIndex, std::string const& _address, std::string const& _begin, int _maxResults) override;
	virtual std::string debug_preimage(std::string const& _hashedKey) override;
	virtual Json::Value debug_traceBlock(std::string const& _blockRlp, Json::Value const& _json);

private:

	aqua::Client const& m_aqua;
	h256 blockHash(std::string const& _blockHashOrNumber) const;
	Json::Value traceTransaction(dev::aqua::Executive& _e, dev::aqua::Transaction const& _t, Json::Value const& _json);
	Json::Value traceBlock(dev::aqua::Block const& _block, Json::Value const& _json);
};

}
}
