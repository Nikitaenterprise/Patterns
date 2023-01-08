#pragma once

#include <memory>

class IStringBuilder;

class UStringDirector
{
public:
	UStringDirector() = delete;
	explicit UStringDirector(const std::shared_ptr<IStringBuilder>& InBuilder);
	void AdditionalConstruct();

private:
	std::shared_ptr<IStringBuilder> Builder = nullptr;
};