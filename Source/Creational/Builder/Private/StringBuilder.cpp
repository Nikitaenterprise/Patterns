#include "../Public/StringBuilder.h"

void UStringBuilderWithAts::FirstStep()
{
	ResultString.append("@@@@@@@@@@@@@@@@");
}

void UStringBuilderWithAts::SecondStep()
{
	ResultString.append("\nI'm string from StringWithAts\n");
}

void UStringBuilderWithAts::ThirdStep()
{
	ResultString.append("@@@@@@@@@@@@@@@@");
}

void UStringBuilderWithAts::PostConstructFlush()
{
	ResultString.clear();
}

void UStringBuilderWithSlashes::FirstStep()
{
	ResultString.append("\\\\\\\\\\\\\\\\\\");
}

void UStringBuilderWithSlashes::SecondStep()
{
	ResultString.append("\nI'm string from StringWithSlashes\n");
}

void UStringBuilderWithSlashes::ThirdStep()
{
	ResultString.append("\\\\\\\\\\\\\\\\\\");
}
