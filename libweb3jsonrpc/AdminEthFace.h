/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_DEV_RPC_ADMINETHFACE_H_
#define JSONRPC_CPP_STUB_DEV_RPC_ADMINETHFACE_H_

#include "ModularServer.h"

namespace dev {
    namespace rpc {
        class AdminEthFace : public ServerInterface<AdminEthFace>
        {
            public:
                AdminEthFace()
                {
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_blockQueueStatus", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_blockQueueStatusI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_setAskPrice", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_setAskPriceI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_setBidPrice", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_setBidPriceI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_setMining", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_BOOLEAN,"param2",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_setMiningI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_findBlock", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_findBlockI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_blockQueueFirstUnknown", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_STRING, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_blockQueueFirstUnknownI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_blockQueueRetryUnknown", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_blockQueueRetryUnknownI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_allAccounts", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_ARRAY, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_allAccountsI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_newAccount", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_OBJECT,"param2",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_newAccountI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_setMiningBenefactor", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_setMiningBenefactorI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_inspect", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_inspectI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_reprocess", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_reprocessI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_vmTrace", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_INTEGER,"param3",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_vmTraceI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("admin_aqua_getReceiptByHashAndIndex", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",jsonrpc::JSON_STRING,"param2",jsonrpc::JSON_INTEGER,"param3",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::admin_aqua_getReceiptByHashAndIndexI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("miner_start", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_INTEGER, NULL), &dev::rpc::AdminEthFace::miner_startI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("miner_stop", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN,  NULL), &dev::rpc::AdminEthFace::miner_stopI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("miner_setEtherbase", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::miner_setEtherbaseI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("miner_setExtra", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::miner_setExtraI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("miner_setGasPrice", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_BOOLEAN, "param1",jsonrpc::JSON_STRING, NULL), &dev::rpc::AdminEthFace::miner_setGasPriceI);
                    this->bindAndAddMaquaod(jsonrpc::Procedure("miner_hashrate", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_STRING,  NULL), &dev::rpc::AdminEthFace::miner_hashrateI);
                }

                inline virtual void admin_aqua_blockQueueStatusI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_blockQueueStatus(request[0u].asString());
                }
                inline virtual void admin_aqua_setAskPriceI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_setAskPrice(request[0u].asString(), request[1u].asString());
                }
                inline virtual void admin_aqua_setBidPriceI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_setBidPrice(request[0u].asString(), request[1u].asString());
                }
                inline virtual void admin_aqua_setMiningI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_setMining(request[0u].asBool(), request[1u].asString());
                }
                inline virtual void admin_aqua_findBlockI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_findBlock(request[0u].asString(), request[1u].asString());
                }
                inline virtual void admin_aqua_blockQueueFirstUnknownI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_blockQueueFirstUnknown(request[0u].asString());
                }
                inline virtual void admin_aqua_blockQueueRetryUnknownI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_blockQueueRetryUnknown(request[0u].asString());
                }
                inline virtual void admin_aqua_allAccountsI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_allAccounts(request[0u].asString());
                }
                inline virtual void admin_aqua_newAccountI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_newAccount(request[0u], request[1u].asString());
                }
                inline virtual void admin_aqua_setMiningBenefactorI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_setMiningBenefactor(request[0u].asString(), request[1u].asString());
                }
                inline virtual void admin_aqua_inspectI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_inspect(request[0u].asString(), request[1u].asString());
                }
                inline virtual void admin_aqua_reprocessI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_reprocess(request[0u].asString(), request[1u].asString());
                }
                inline virtual void admin_aqua_vmTraceI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_vmTrace(request[0u].asString(), request[1u].asInt(), request[2u].asString());
                }
                inline virtual void admin_aqua_getReceiptByHashAndIndexI(const Json::Value &request, Json::Value &response)
                {
                    response = this->admin_aqua_getReceiptByHashAndIndex(request[0u].asString(), request[1u].asInt(), request[2u].asString());
                }
                inline virtual void miner_startI(const Json::Value &request, Json::Value &response)
                {
                    response = this->miner_start(request[0u].asInt());
                }
                inline virtual void miner_stopI(const Json::Value &request, Json::Value &response)
                {
                    (void)request;
                    response = this->miner_stop();
                }
                inline virtual void miner_setEtherbaseI(const Json::Value &request, Json::Value &response)
                {
                    response = this->miner_setEtherbase(request[0u].asString());
                }
                inline virtual void miner_setExtraI(const Json::Value &request, Json::Value &response)
                {
                    response = this->miner_setExtra(request[0u].asString());
                }
                inline virtual void miner_setGasPriceI(const Json::Value &request, Json::Value &response)
                {
                    response = this->miner_setGasPrice(request[0u].asString());
                }
                inline virtual void miner_hashrateI(const Json::Value &request, Json::Value &response)
                {
                    (void)request;
                    response = this->miner_hashrate();
                }
                virtual Json::Value admin_aqua_blockQueueStatus(const std::string& param1) = 0;
                virtual bool admin_aqua_setAskPrice(const std::string& param1, const std::string& param2) = 0;
                virtual bool admin_aqua_setBidPrice(const std::string& param1, const std::string& param2) = 0;
                virtual bool admin_aqua_setMining(bool param1, const std::string& param2) = 0;
                virtual Json::Value admin_aqua_findBlock(const std::string& param1, const std::string& param2) = 0;
                virtual std::string admin_aqua_blockQueueFirstUnknown(const std::string& param1) = 0;
                virtual bool admin_aqua_blockQueueRetryUnknown(const std::string& param1) = 0;
                virtual Json::Value admin_aqua_allAccounts(const std::string& param1) = 0;
                virtual Json::Value admin_aqua_newAccount(const Json::Value& param1, const std::string& param2) = 0;
                virtual bool admin_aqua_setMiningBenefactor(const std::string& param1, const std::string& param2) = 0;
                virtual Json::Value admin_aqua_inspect(const std::string& param1, const std::string& param2) = 0;
                virtual Json::Value admin_aqua_reprocess(const std::string& param1, const std::string& param2) = 0;
                virtual Json::Value admin_aqua_vmTrace(const std::string& param1, int param2, const std::string& param3) = 0;
                virtual Json::Value admin_aqua_getReceiptByHashAndIndex(const std::string& param1, int param2, const std::string& param3) = 0;
                virtual bool miner_start(int param1) = 0;
                virtual bool miner_stop() = 0;
                virtual bool miner_setEtherbase(const std::string& param1) = 0;
                virtual bool miner_setExtra(const std::string& param1) = 0;
                virtual bool miner_setGasPrice(const std::string& param1) = 0;
                virtual std::string miner_hashrate() = 0;
        };

    }
}
#endif //JSONRPC_CPP_STUB_DEV_RPC_ADMINETHFACE_H_
