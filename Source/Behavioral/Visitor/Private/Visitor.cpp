#include "../Public/Visitor.h"

void UVisitor::VisitFirst(const IVisitorElement& InElement)
{
	std::cout << "UVisitor visits element with fist method with data " << InElement.GetData() << "\n";
}

void UVisitor::VisitSecond(const IVisitorElement& InElement)
{
	std::cout << "UVisitor visits element with second method with data " << InElement.GetData() << "\n";
}