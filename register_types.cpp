#include "register_types.h"

#include "core/class_db.h"
#include "socketio_client.h"
#include "socketio_socket.h"

void register_gdsocketio_types() {
	ClassDB::register_class<SocketIOSocket>();
	ClassDB::register_class<SocketIOClient>();
}

void unregister_gdsocketio_types() {
	// Nothing to do here in this example.
}