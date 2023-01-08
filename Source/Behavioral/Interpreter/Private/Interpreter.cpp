#include "../Public/Interpreter.h"
#include "../Public/Context.h"

bool VariableExpression::Evaluate(Context& ThatContext)
{
	const std::string& Value = ThatContext.Lookup(Name) ? "true" : "false";
	std::cout << "Evaluating context " << Value << "\n";
	return ThatContext.Lookup(Name);
}

std::shared_ptr<BooleanExpression> VariableExpression::Replace(const std::string& Input, const BooleanExpression& ThatExpression)
{
	if (Name == Input)
	{
		return ThatExpression.Copy();
	}
	return std::shared_ptr<BooleanExpression>(new VariableExpression(Name));
}

std::shared_ptr<BooleanExpression> VariableExpression::Copy() const
{
	return std::shared_ptr<BooleanExpression>(new VariableExpression(Name));
}

bool AndExpression::Evaluate(Context& That)
{
	const std::string& FirstValue = First->Evaluate(That) ? "true" : "false";
	const std::string& SecondValue = Second->Evaluate(That) ? "true" : "false";
	std::cout << "Evaluating AndExpression " << FirstValue << " " << SecondValue << "\n";
	return First->Evaluate(That) && Second->Evaluate(That);
}

std::shared_ptr<BooleanExpression> AndExpression::Replace(const std::string& Input, const BooleanExpression& ThatExpression)
{
	return std::shared_ptr<BooleanExpression>(new AndExpression(First->Replace(Input, ThatExpression), Second->Replace(Input, ThatExpression)));
}

std::shared_ptr<BooleanExpression> AndExpression::Copy() const
{
	return std::shared_ptr<BooleanExpression>(new AndExpression(First->Copy(), Second->Copy()));
}

bool OrExpression::Evaluate(Context& That)
{
	const std::string& FirstValue = First->Evaluate(That) ? "true" : "false";
	const std::string& SecondValue = Second->Evaluate(That) ? "true" : "false";
	std::cout << "Evaluating OrExpression " << FirstValue << " " << SecondValue << "\n";
	return First->Evaluate(That) || Second->Evaluate(That);
}

std::shared_ptr<BooleanExpression> OrExpression::Replace(const std::string& Input, const BooleanExpression& ThatExpression)
{
	return std::shared_ptr<BooleanExpression>(new OrExpression(First->Replace(Input, ThatExpression), Second->Replace(Input, ThatExpression)));
}

std::shared_ptr<BooleanExpression> OrExpression::Copy() const
{
	return std::shared_ptr<BooleanExpression>(new OrExpression(First->Copy(), Second->Copy()));
}

bool NotExpression::Evaluate(Context& That)
{
	const std::string& FirstValue = First->Evaluate(That) ? "true" : "false";
	std::cout << "Evaluating NotExpression " << FirstValue << "\n";
	return !First->Evaluate(That);
}

std::shared_ptr<BooleanExpression> NotExpression::Replace(const std::string& Input, const BooleanExpression& ThatExpression)
{
	return First->Replace(Input, ThatExpression);
}

std::shared_ptr<BooleanExpression> NotExpression::Copy() const
{
	return First->Copy();
}