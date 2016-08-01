#include "aibot.h"

Nan::Persistent <v8::Function> AIBot::constructor;

AIBot::AIBot(double value) : value_(value) {
}

AIBot::~AIBot() {
}

void AIBot::Init(v8::Local <v8::Object> exports) {
  Nan::HandleScope scope;

  // Prepare constructor template
  v8::Local <v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New<v8::String>("AIBot").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  Nan::SetPrototypeMethod(tpl, "value", GetValue);
  Nan::SetPrototypeMethod(tpl, "hello", Hello);
  Nan::SetPrototypeMethod(tpl, "plusOne", PlusOne);
  Nan::SetPrototypeMethod(tpl, "multiply", Multiply);

  constructor.Reset(tpl->GetFunction());
  exports->Set(Nan::New("AIBot").ToLocalChecked(), tpl->GetFunction());
  exports->Set(Nan::New("hello").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(Hello)->GetFunction());
}

void AIBot::New(const Nan::FunctionCallbackInfo <v8::Value> &info) {
  if (info.IsConstructCall()) {
    // Invoked as constructor: `new AIBot(...)`
    double value = info[0]->IsUndefined() ? 0 : info[0]->NumberValue();
    AIBot *aibot = new AIBot(value);
    aibot->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  } else {
    // Invoked as plain function `AIBot(...)`, turn into construct call.
    const int argc = 1;
    v8::Local <v8::Value> argv[argc] = {info[0]};
    v8::Local <v8::Function> cons = Nan::New<v8::Function>(constructor);
    info.GetReturnValue().Set(cons->NewInstance(argc, argv));
  }
}

void AIBot::GetValue(const Nan::FunctionCallbackInfo <v8::Value> &info) {
  AIBot *aibot = ObjectWrap::Unwrap<AIBot>(info.Holder());
  info.GetReturnValue().Set(Nan::New(aibot->value_));
}

void AIBot::PlusOne(const Nan::FunctionCallbackInfo <v8::Value> &info) {
  AIBot *aibot = ObjectWrap::Unwrap<AIBot>(info.Holder());
  aibot->value_ += 1;
  info.GetReturnValue().Set(Nan::New(aibot->value_));
}

void AIBot::Multiply(const Nan::FunctionCallbackInfo <v8::Value> &info) {
  AIBot *aibot = ObjectWrap::Unwrap<AIBot>(info.Holder());
  double multiple = info[0]->IsUndefined() ? 1 : info[0]->NumberValue();

  v8::Local <v8::Function> cons = Nan::New<v8::Function>(constructor);

  const int argc = 1;
  v8::Local <v8::Value> argv[argc] = {Nan::New(aibot->value_ * multiple)};

  info.GetReturnValue().Set(cons->NewInstance(argc, argv));
}

void AIBot::Hello(const Nan::FunctionCallbackInfo <v8::Value> &info) {
  info.GetReturnValue().Set(Nan::New("Hello World!").ToLocalChecked());

}