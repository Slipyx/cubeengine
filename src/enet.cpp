#define ENET_IMPLEMENTATION
#include "enet.h"

// missing func impl
int enet_packet_resize(ENetPacket* packet, size_t dataLength)
{
	enet_uint8* newData;

	if (dataLength <= packet->dataLength || (packet->flags & ENET_PACKET_FLAG_NO_ALLOCATE))
	{
		packet->dataLength = dataLength;
		return 0;
	}

	newData = (enet_uint8*)enet_malloc(dataLength);
	if (newData == NULL)
		return -1;

	memcpy(newData, packet->data, packet->dataLength);
	enet_free(packet->data);

	packet->data = newData;
	packet->dataLength = dataLength;

	return 0;
}

