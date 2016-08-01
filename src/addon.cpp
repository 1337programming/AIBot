#include "../node_modules/nan/nan.h"
#include "node/node.h"
#include "aibot.h"

void InitAll(v8::Local<v8::Object> exports) {
	AIBot::Init(exports);
 //Prototype::Initialize(exports);
}

NODE_MODULE(addon, InitAll)