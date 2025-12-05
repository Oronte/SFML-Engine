#include "FontManager.h"

engine::FontManager::FontManager()
{
	std::filesystem::create_directories(fontPath);
	LoadDefaultFont();
}

void engine::FontManager::LoadDefaultFont()
{
	SetFontToDefault(defaultFont);
}

void engine::FontManager::SetFontToDefault(Font& _font)
{
	const std::string& _finalPath = defaultFontPath + "." + defaultFontExtension;
	LoadFont(_font, _finalPath);
}

std::string engine::FontManager::GetExtensionNameByType(const FontExtensionType& _fontType) const
{
	const std::string _extensionNames[] =
	{
		"otf",
		"ttf",
	};

	return _extensionNames[(int)_fontType];
}

void engine::FontManager::LoadFont(Font& _font, const std::string& _fullName)
{
	const std::string& _finalPath = fontPath + _fullName;

	if (!_font.Open(_finalPath))
	{
		LOG(VerbosityType::Error, "Cannot open file with the following path : \'" + _finalPath + "\' !");
		SetFontToDefault(_font);
	}
}

void engine::FontManager::LoadFont(Font& _font, const std::string& _fileName, const FontExtensionType& _fontType)
{
	const std::string& _finalPath = fontPath + _fileName + "." + GetExtensionNameByType(_fontType);

	if (!_font.Open(_finalPath))
	{
		LOG(VerbosityType::Error, "Cannot open file with the following path : \'" + _finalPath + "\' !");
		SetFontToDefault(_font);
	}
}
