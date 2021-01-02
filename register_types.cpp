#include "register_types.h"

#include "core/class_db.h"
#include "tts.h"

void register_socketio_types() {
    ClassDB::register_class<TTS>();
}

void unregister_socketio_types() {
    // Nothing to do here in this example.
}