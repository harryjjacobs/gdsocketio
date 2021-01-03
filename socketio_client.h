#ifndef GDSOCKETIO_CLIENT_H
#define GDSOCKETIO_CLIENT_H

#include "core/reference.h"

#include "lib/socket.io-client-cpp/src/sio_client.h"

#include "socketio_socket.h"

class SocketIOClient : public Reference {
	GDCLASS(SocketIOClient, Reference);

protected:
	static void _bind_methods();

public:
	SocketIOClient();
	void open(String p_url);
	Ref<SocketIOSocket> socket(String p_nsp);

private:
	sio::client client;
};

#endif // GDSOCKETIO_H