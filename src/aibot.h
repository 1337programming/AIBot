#ifndef AIBOT_H
#define AIBOT_H

#include "node/node.h"
#include "node/v8.h"
#include "../node_modules/nan/nan.h"

#include "time.h"


class AIBot : public Nan::ObjectWrap {
public:
  static void Init(v8::Local<v8::Object> exports);

private:
  explicit AIBot(double value = 0, char* result = "", Time timer = (10, 50, 59));

  ~AIBot();

  static void New(const Nan::FunctionCallbackInfo<v8::Value> &info);

  static void GetValue(const Nan::FunctionCallbackInfo<v8::Value> &info);

  static void GetResult(const Nan::FunctionCallbackInfo<v8::Value> &info);

  static void PlusOne(const Nan::FunctionCallbackInfo<v8::Value> &info);

  static void Multiply(const Nan::FunctionCallbackInfo<v8::Value> &info);

  static void PrintTime(const Nan::FunctionCallbackInfo<v8::Value> &info);

  static Nan::Persistent<v8::Function> constructor;

  double value_;
  char *result_;
  Time timer_;
};

#endif