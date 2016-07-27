#include "aibot.h"

Nan::Persistent<v8::Function> AIBot::constructor;

AIBot::AIBot(double value, char *result, Time timer) : value_(value), result_(result), timer_(timer) {
}

AIBot::~AIBot() {
}

void AIBot::Init(v8::Local<v8::Object> exports) {
  Nan::HandleScope scope;

  // Prepare constructor template
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("AIBot").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  Nan::SetPrototypeMethod(tpl, "value", GetValue);
  Nan::SetPrototypeMethod(tpl, "result", GetResult);
  Nan::SetPrototypeMethod(tpl, "plusOne", PlusOne);
  Nan::SetPrototypeMethod(tpl, "multiply", Multiply);
  Nan::SetPrototypeMethod(tpl, "printTime", PrintTime);

  constructor.Reset(tpl->GetFunction());
  exports->Set(Nan::New("AIBot").ToLocalChecked(), tpl->GetFunction());
}

void AIBot::New(const Nan::FunctionCallbackInfo<v8::Value> &info) {
  if (info.IsConstructCall()) {
    // Invoked as constructor: `new AIBot(...)`
    double value = 0;
    char* result = "";
    int time [3] = {0, 0, 0};
    if (!info[0]->IsUndefined()) {
      value = info[0]->NumberValue();
    }
    if (!info[1]->IsUndefined()) {
      result = info[1]->Uint32Value();
    }
    if (!info[2]->IsUndefined()) {
      time = info[2];
    }
    AIBot *obj = new AIBot(value, result, time);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  } else {
    // Invoked as plain function `AIBot(...)`, turn into construct call.
    /*const int argc = 1;
    v8::Local<v8::Value> argv[argc] = {info[0]};
    v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
    info.GetReturnValue().Set(cons->NewInstance(argc, argv));*/
  }
}

void AIBot::GetValue(const Nan::FunctionCallbackInfo<v8::Value> &info) {
  AIBot *obj = ObjectWrap::Unwrap<AIBot>(info.Holder());
  info.GetReturnValue().Set(Nan::New(obj->value_));
}

void AIBot::GetResult(const Nan::FunctionCallbackInfo<v8::Value> &info) {
  AIBot *obj = ObjectWrap::Unwrap<AIBot>(info.Holder());
  //info.GetReturnValue().Set(Nan::New(obj->result_));
}

void AIBot::PlusOne(const Nan::FunctionCallbackInfo<v8::Value> &info) {
  AIBot *obj = ObjectWrap::Unwrap<AIBot>(info.Holder());
  obj->value_ += 1;
  info.GetReturnValue().Set(Nan::New(obj->value_));
}

void AIBot::Multiply(const Nan::FunctionCallbackInfo<v8::Value> &info) {
  AIBot *obj = ObjectWrap::Unwrap<AIBot>(info.Holder());
  double multiple;
  if (info[0]->IsUndefined()) {
    multiple = 1;
  }
  else {
    multiple = info[0]->NumberValue();
  }

  v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);

  const int argc = 1;
  v8::Local<v8::Value> argv[argc] = {Nan::New(obj->value_ * multiple)};

  info.GetReturnValue().Set(cons->NewInstance(argc, argv));
}

void AIBot::PrintTime(const Nan::FunctionCallbackInfo<v8::Value> &info) {
  AIBot *obj = ObjectWrap::Unwrap<AIBot>(info.Holder());
  obj->result_ = obj->timer_.print();
  info.GetReturnValue().Set(Nan::New(obj->result_));
}