#pragma once

enum class EPlatform
{
	Windows,
	Mac,

	NONE,
	Count
};

class ForTests
{
public:
	ForTests() = delete;
	explicit ForTests(EPlatform InCurrentPlatform);

protected:
	EPlatform CurrentPlatform = EPlatform::NONE;
};

