#include "socketio_socket.h"

SocketIOSocket::SocketIOSocket() :
		socket(nullptr) {
}

void SocketIOSocket::_bind_methods() {
	ClassDB::bind_method(D_METHOD("emit", "name", "message"), &SocketIOSocket::connect);
	ClassDB::bind_method(D_METHOD("on", "name", "callback_func"), &SocketIOSocket::connect);
}

void SocketIOSocket::set_socket(sio::socket::ptr socket) {
	this->socket = socket;
}

void SocketIOSocket::emit(String p_name, String p_message) {
	const std::string name(p_name.utf8().ptr());
	const std::string message(p_message.utf8().ptr());
	socket->emit(name, message);
}

void SocketIOSocket::on(String p_name, Ref<FuncRef> p_callback) {
	const std::string name(p_name.utf8().ptr());

	socket->on(
			name, std::bind(&SocketIOSocket::message_handler, this, std::placeholders::_1, p_callback));
}

void SocketIOSocket::message_handler(const sio::event &event, Ref<FuncRef> p_callback) {
	Variant message = convert_message_to_variant(event.get_message());
	const Variant *callback_params[] = { &message };
	Variant::CallError call_error;
	p_callback->call_func(callback_params, 1, call_error);
}

Variant SocketIOSocket::convert_message_to_variant(const sio::message::ptr message) {
	switch (message->get_flag()) {
		case sio::message::flag_string: {
			String message_string = message->get_string().c_str();
			return message_string;
		}
		case sio::message::flag_integer: {
			return message->get_int();
		}
		case sio::message::flag_double: {
			return message->get_double();
		}
		case sio::message::flag_boolean: {
			return message->get_bool();
		}
		case sio::message::flag_binary: {
			String message_binary_string = message->get_binary()->c_str();
			return message_binary_string;
		}
		case sio::message::flag_null: {
			return Variant();
		}
		case sio::message::flag_array: {
			Array message_array;
			for (const auto &arr_message : message->get_vector()) {
				message_array.push_back(convert_message_to_variant(arr_message));
			}
			return message_array;
		}
		case sio::message::flag_object: {
			Dictionary message_map;
			const auto map = message->get_map();
			for (const auto &pair : map) {
				message_map[pair.first.c_str()] = convert_message_to_variant(pair.second);
			}
			return message_map;
		}
		default:
			return Variant();
			break;
	}
}