// Copyright (C) 2010 Nikhil Marathe <nsm.nikhil@gmail.com>

#ifndef _LIBUUID_V8_
#define _LIBUUID_V8_

#include <uuid/uuid.h>
#include <v8.h>
#include <node.h>

namespace uuid_v8 {
void Initialize( v8::Handle<v8::Object> target );
v8::Handle<v8::Value> GenerateRandom( const v8::Arguments &args );
v8::Handle<v8::Value> GenerateTime( const v8::Arguments &args );
}
#endif
