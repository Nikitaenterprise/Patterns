#include "../Public/VisitorElement.h"

void UFirstVisitorElement::AcceptVisitor(const std::unique_ptr<IVisitor>& InVisitor) const
{
	std::cout << "Accepting visitor\n";
	InVisitor->VisitFirst(*this);
}

void USecondVisitorElement::AcceptVisitor(const std::unique_ptr<IVisitor>& InVisitor) const
{
	std::cout << "Accepting visitor\n";
	InVisitor->VisitSecond(*this);
}