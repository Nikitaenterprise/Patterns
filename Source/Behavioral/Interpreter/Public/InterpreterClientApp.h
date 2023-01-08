#pragma once

#include "Context.h"
#include "Interpreter.h"
#include <iostream>

class InterpreterClientApp
{
public:
	InterpreterClientApp()
	{
		std::shared_ptr<BooleanExpression> X = std::shared_ptr<VariableExpression>(new VariableExpression("X"));
		Context FirstContext;
		FirstContext.Assign(X, false);

		// FirstExpression = !X
		std::shared_ptr<BooleanExpression> FirstExpression = std::shared_ptr<BooleanExpression>(new NotExpression(X));
		bool FirtsResult = FirstExpression->Evaluate(FirstContext);
		std::cout << FirstContext << "\n";
		std::cout << "FirstExpression = !X" << " is " << (FirtsResult ? "true" : "false") << "\n";

		std::shared_ptr<BooleanExpression> Y = std::shared_ptr<VariableExpression>(new VariableExpression("Y"));
		std::shared_ptr<BooleanExpression> Z = std::shared_ptr<VariableExpression>(new VariableExpression("Z"));
		Context SecondContext;
		SecondContext.Assign(Y, false);
		SecondContext.Assign(Z, false);
		
		// SecondExpression = Y && !Z
		std::shared_ptr<BooleanExpression> SecondExpression = std::shared_ptr<BooleanExpression>(
			new AndExpression(
				Y,
				std::make_shared<NotExpression>(Z)
		));
		bool SecondResult = SecondExpression->Evaluate(SecondContext);
		std::cout << SecondContext << "\n";
		std::cout << "SecondExpression = Y && !Z" << " is " << (SecondResult ? "true" : "false") << "\n";

		Context ThirdContext;
		ThirdContext.Assign(X, true);
		ThirdContext.Assign(Y, true);
		ThirdContext.Assign(Z, true);

		// ThirdExpression = X && (Y || !Z)
		std::shared_ptr<BooleanExpression> ThirdExpression = std::shared_ptr<BooleanExpression>(
			new AndExpression(
				X,
				std::shared_ptr<BooleanExpression>(
					new OrExpression(
						Y,
						std::make_shared<NotExpression>(Z)
		))));
		bool ThirdResult = ThirdExpression->Evaluate(ThirdContext);
		std::cout << ThirdContext << "\n";
		std::cout << "ThirdExpression = X && (Y || !Z)" << " is " << (ThirdResult ? "true" : "false") << "\n";
	}
};