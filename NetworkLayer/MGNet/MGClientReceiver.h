#pragma once
#include "asios.h"
#include <map>
#include <EngineInterface/ISession.h>

class INetworkEngine;

class MGClientReceiver : public INetworkReceiver, public ISession
{
	typedef std::map<long, ASSOCKDESCEX> SessionMap;
public:
	MGClientReceiver(INetworkEngine* pOwner);
	virtual ~MGClientReceiver(void);

	virtual void notifyRegisterSocket(ASSOCKDESCEX& sockdesc, SOCKADDR_IN& ip) override;
	virtual void notifyReleaseSocket(ASSOCKDESCEX& sockdesc) override;
	virtual void notifyMessage(ASSOCKDESCEX& sockdesc, size_t length, char* data) override;
	virtual void notifyConnectingResult(INT32 requestID, ASSOCKDESCEX& sockdesc, DWORD error);

	virtual bool SendRequest(BasePacket* pPacket) override;

	bool Disconnect(int serial);

protected:

private:
//멀티쓰레드로 접근해서
	SessionMap m_sessionMap;
	CriticalSectionLock m_sessionLock;
	ASSOCKDESCEX m_socketDesc;
	
	INetworkEngine* m_pOwner;
};