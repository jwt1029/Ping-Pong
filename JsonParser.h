#pragma once
#ifndef __JsonParser__
#define __JsonParser__

#include "Authentication.h"
#include "json.hpp"
#include "TemplateSingleton.h"
#include "GameManager.h"
using json = nlohmann::json;

#define JSONPARSER JsonParser::JsonParser::GetInstance()

namespace JsonParser
{
	class JsonParser : public TemplateSingleton<JsonParser>{
	private:
		json js;
		int status;
	public:
		JsonParser();
		~JsonParser();
		JsonParser(const char * buf);
		json parse(const char * buf);
		void process();
		json getType();
	};
}

#endif // __Connection__