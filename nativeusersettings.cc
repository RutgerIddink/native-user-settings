#include <napi.h>

#ifdef _WIN32

#include <windows.h>
#include <Winuser.h>

int GetPrimaryButton() {
  return GetSystemMetrics(SM_SWAPBUTTON);
}

#else

int GetPrimaryButton() {
  return 0;
}

#endif


Napi::String GetPrimaryMouseButton(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  auto res = GetPrimaryButton() == 1 ? "right" : "left";

  return Napi::String::New(env, res);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "getPrimaryMouseButton"),
              Napi::Function::New(env, GetPrimaryMouseButton));
  return exports;
}

NODE_API_MODULE(nativeusersettings, Init)
