#include "socketio_client.h"

void SocketIOClient::open(String p_url) {
	const char *url = p_url.utf8().ptr();
	client.connect(url);
}

Ref<SocketIOSocket> SocketIOClient::socket(String p_nsp) {
	const char *nsp = p_nsp.utf8().ptr();
	Ref<SocketIOSocket> p_socket(memnew(SocketIOSocket()));
	p_socket->set_socket(client.socket(nsp));
	return p_socket;
}

void SocketIOClient::_bind_methods() {
	ClassDB::bind_method(D_METHOD("open", "url"), &SocketIOClient::open);
	ClassDB::bind_method(D_METHOD("socket", "nsp"), &SocketIOClient::socket);
}

SocketIOClient::SocketIOClient() {
}