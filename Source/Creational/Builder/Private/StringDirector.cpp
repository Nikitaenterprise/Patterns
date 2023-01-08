#include "../Public/StringDirector.h"
#include "../Public/StringBuilder.h"

UStringDirector::UStringDirector(const std::shared_ptr<IStringBuilder>& InBuilder) : Builder(InBuilder)
{
	if (Builder)
	{
		Builder->Flush();
		Builder->FirstStep();
		Builder->SecondStep();
		Builder->ThirdStep();
	}
}

void UStringDirector::AdditionalConstruct()
{
	if (Builder)
	{
		Builder->PostConstructFlush();
		Builder->FirstStep();
		Builder->ThirdStep();
	}
}
