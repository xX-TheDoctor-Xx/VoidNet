// https://github.com/mfichman/http

#pragma once

#include <string>

namespace std::net
{
	template <typename T>
	class ParseResult 
	{
	public:
		T value;
		char const* ch;
	};

	template <typename F>
	static ParseResult<string> ParseUntil(char const* str, F func)
	{
		ParseResult<string> result{};
		char const* ch = str;
		for (; *ch && !func(*ch); ++ch)
		{
		}

		result.value = string(str, ch - str);
		result.ch = ch;
		return result;
	}

	template <typename F>
	static inline ParseResult<string> ParseWhile(char const* str, F func) 
	{
		ParseResult<string> result{};
		char const* ch = str;
		for (; *ch && func(*ch); ++ch) 
		{
		}

		result.value = string(str, ch - str);
		result.ch = ch;
		return result;
	}

	static inline ParseResult<string> ParseToken(char const* str) 
	{
		auto token = ParseUntil(str, isspace);
		token.ch = ParseWhile(token.ch, isspace).ch;
		return token;
	}

	static inline ParseResult<string> parseCrLf(char const* str) 
	{
		auto cr = ParseUntil(str, [](char ch) { return ch == '\r'; });
		if (*cr.ch == '\r')
			cr.ch++;
		return ParseWhile(cr.ch, [](char ch) 
		{ 
			return isspace(ch) && ch != '\r'; 
		});
	}

	static inline ParseResult<string> ParseWhitespace(char const* str) 
	{
		return ParseWhile(str, isspace);
	}
}