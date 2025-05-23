// src/hello.cc
#include <napi.h> // Node API (N-API) header

// Função que será exposta ao JavaScript
Napi::Value Method(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env(); // Objeto de ambiente N-API

    // Retorna uma string "world"
    return Napi::String::New(env, "world");
}

// Função de inicialização do módulo
Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    // Adiciona a função 'Method' ao objeto 'exports' (que é o objeto retornado quando o módulo é carregado no JS)
    exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Method));
    return exports;
}

// Declaração do módulo N-API
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)