#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

// define types
typedef rapidjson::Document Json;
typedef rapidjson::Value Value;
typedef rapidjson::GenericDocument<rapidjson::UTF16<> > WJson;
typedef rapidjson::GenericValue<rapidjson::UTF16<> > WValue;
