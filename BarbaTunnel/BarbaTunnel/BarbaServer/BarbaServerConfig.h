#pragma once
#include "General.h"

class BarbaServerConfigItem
{
public:
	BarbaServerConfigItem();
	BarbaModeEnum Mode;
	PortRange ListenPorts[BARBA_MAX_PORTITEM];
	int ListenPortsCount;
	u_short RealPort; //valid when mode is UDP-Redirect or TCP-Redirect mode
	bool Enabled;
};

class BarbaServerConfig
{
public:
	BarbaServerConfig();

	bool DebugMode;
	IpRange VirtualIpRange;
	int AdapterIndex;
	BYTE Key[BARBA_MAX_KEYLEN];
	int KeyCount;
	bool LoadFile(LPCTSTR file);

	BarbaServerConfigItem Items[MAX_BARBA_CONFIGITEMS];
	int ItemsCount;

private:
	//@param value: Protocol:Port,Protocol:Port ; eg: TCP:80,TCP:429,TCP:*,1:0
	static void ParseListenPorts(BarbaServerConfigItem* item, LPCTSTR value);
};