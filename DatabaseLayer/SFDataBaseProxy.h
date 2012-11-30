#pragma once

class BasePacket;

class SFDatabaseProxy
{
public:
	SFDatabaseProxy(void){}
	virtual ~SFDatabaseProxy(void){}

	virtual BOOL Initialize() = 0;
	virtual BOOL SendDBRequest(BasePacket* pMessage) = 0;

protected:

private:
};
