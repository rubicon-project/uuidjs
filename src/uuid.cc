// Copyright (C) 2010 Nikhil Marathe <nsm.nikhil@gmail.com>

#include "uuid.h"

#include <cstring>

using namespace v8;
using namespace node;

extern "C"
void init( Handle<Object> target ) {
  HandleScope scope;
  uuid_v8::Initialize( target );
}

namespace uuid_v8 {

void Initialize( Handle<Object> target ) {
  HandleScope scope;

  Local<FunctionTemplate> trandom = FunctionTemplate::New(GenerateRandom);
  Local<FunctionTemplate> ttime = FunctionTemplate::New(GenerateTime);

  target->Set( String::NewSymbol( "generateRandom" ), trandom->GetFunction() );
  target->Set( String::NewSymbol( "generateTime" ), ttime->GetFunction() );
}

Handle<Value> GenerateRandom( const Arguments &args ) {
  HandleScope scope;

  uuid_t new_uuid;
  encoding encode = ASCII;
  char unparsed[40];

  uuid_generate_random(new_uuid);
  uuid_unparse( new_uuid, unparsed );
  return Encode(unparsed, strlen(unparsed), encode);
}

Handle<Value> GenerateTime( const Arguments &args ) {
  HandleScope scope;

  uuid_t new_uuid;
  encoding encode = ASCII;
  char unparsed[40];

  uuid_generate_time(new_uuid);
  uuid_unparse( new_uuid, unparsed );
  return Encode(unparsed, strlen(unparsed), encode);
}

}
