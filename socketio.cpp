#ifndef GODOT_SOCKETIO_H
#define GODOT_SOCKETIO_H

#include "core/reference.h"

class SocketIO : public Reference {
    GDCLASS(SocketIO, Reference);

protected:
    static void _bind_methods();

public:
    SocketIO();
    void connect(String p_url);
};

#endif // GODOT_TTS_H