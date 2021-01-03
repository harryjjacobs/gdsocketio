#ifndef GDSOCKETIO_SOCKET_H
#define GDSOCKETIO_SOCKET_H

#include "core/func_ref.h"
#include "core/reference.h"

#include "lib/socket.io-client-cpp/src/sio_message.h"
#include "lib/socket.io-client-cpp/src/sio_socket.h"

class SocketIOSocket : public Reference {
	GDCLASS(SocketIOSocket, Reference);

protected:
	static void _bind_methods();

public:
	SocketIOSocket();
	void set_socket(sio::socket::ptr socket);
	void emit(String p_name, String p_message);
	void on(String p_name, Ref<FuncRef> p_callback);

private:
	void message_handler(const sio::event &event, Ref<FuncRef> p_callback);
	Variant convert_message_to_variant(const sio::message::ptr message);

private:
	sio::socket::ptr socket;
};

#endif // GDSOCKETIO_H