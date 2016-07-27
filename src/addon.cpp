#include "../node_modules/nan/nan.h"
#include "aibot.h"
#include "node/node.h"

void InitAll(v8::Local<v8::Object> exports) {
	AIBot::Init(exports);
}

NODE_MODULE(addon, InitAll)