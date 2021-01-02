#include "socketio.h"

//#include <festival.h>

void SocketIO::connect(String p_url) {
    //convert Godot String to Godot CharString to C string
    //return festival_say_text(p_txt.ascii().get_data());
}

void SocketIO::_bind_methods() {
    ClassDB::bind_method(D_METHOD("connect", "url"), &SocketIO::connect);
}

SocketIO::SocketIO() {
    //festival_initialize(true, 210000);
}