#pragma once
#include "BarbaCourierDatagram.h"
#include "BarbaPortRange.h"

class BarbaCourierUdpClient : public BarbaCourierDatagram
{
public:
	class CreateStrcutUdp : public CreateStrcut
	{
		CreateStrcutUdp() {RemoteIp=0; PortRange=NULL;}
		DWORD RemoteIp;
		BarbaPortRange* PortRange;
	};

	BarbaCourierUdpClient(void);
	virtual ~BarbaCourierUdpClient(void);
	CreateStrcutUdp* GetCreateStruct() {return (CreateStrcutUdp*)BarbaCourierDatagram::GetCreateStruct();}

protected:
	virtual void SendPacketToOutbound(PacketHelper* packet)=0;
};
