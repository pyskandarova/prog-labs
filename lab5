#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Функция для вычисления приоритета оператора
    if (c=='+' || c=='-'){
        return 1;
    };
    if (c=='*' || c=='/'){
        return 2;
    };
    if (c=='^'){
        return 3;
    };
    return 0;
}

// Функция для выполнения операции над двумя операндами
double performOperation(char operation, double operand1, double operand2) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return pow(operand1, operand2);
        default:
            return 0.0;
    }
}

// Функция для вывода шагового решения
void printStep(const string& step, const stack<double>& operands, const stack<char>& operators) {
    cout << step << " | Operands: [";

    stack<double> tempOperands = operands;
    while (!tempOperands.empty()) {
        cout << tempOperands.top();
        tempOperands.pop();
        if (!tempOperands.empty())
            cout << ", ";
    }

    cout << "] | Operators: [";

    stack<char> tempOperators = operators;
    while (!tempOperators.empty()) {
        cout << tempOperators.top();
        tempOperators.pop();
        if (!tempOperators.empty())
            cout << ", ";
    }

    cout << "]" << endl;
}

// Рекурсивная функция для "парсинга" и вычисления выражения
double evaluateExpression(const string& expression) {
    stack<double> operands;
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        char currentChar = expression[i];

        if (currentChar == ' ')
            continue;

        if (isdigit(currentChar)||(operands.empty()&&(currentChar == '-' || currentChar == '+'))) {
            // Считываем операнд
            string operand;
            operand += expression[i];
            i++;
            while ((i < expression.length()) 
                    && (isdigit(expression[i]) || expression[i] == '.' )
                  ) {
                operand += expression[i];
                i++;
            }
            i--;

            // Преобразуем строку в число и помещаем в стек операндов
            double num = stod(operand);
            operands.push(num);

            // Вывод шагового решения
            printStep("Operand Push: " + operand, operands, operators);
        } else if ((currentChar == '(') || (currentChar == '[')) {
            // Открывающую скобку помещаем в стек операторов
            operators.push(currentChar);

            // Вывод шагового решения
            printStep("Operator Push: " + string(1, currentChar), operands, operators);
        } else if ((currentChar == ')') || (currentChar == ']')) {
            // Выполняем операции до тех пор, пока не встретим открывающую скобку
            while (!operators.empty() && !((operators.top() == '(') || (operators.top() == '['))) {
                char op = operators.top();
                operators.pop();

                double operand2 = operands.top();
                operands.pop();

                double operand1 = operands.top();
                operands.pop();

                double result = performOperation(op, operand1, operand2);
                operands.push(result);

                // Вывод шагового решения
                printStep("Operation: " + string(1, op), operands, operators);
            }

            if (!operators.empty())
                operators.pop();  // Удаляем открывающую скобку из стека операторов

            // Вывод шагового решения
            printStep("Operator Pop: " + string(1, currentChar), operands, operators);
        } else if (getOpPrior(currentChar)>0) {
            // Выполняем операции с более высоким или равным приоритетом
            while (!operators.empty() && !((operators.top() == '(') || (operators.top() == '[')) &&
                    (getOpPrior(currentChar)<=getOpPrior(operators.top()))) {
                char op = operators.top();
                operators.pop();

                double operand2 = operands.top();
                operands.pop();

                double operand1 = operands.top();
                operands.pop();

                double result = performOperation(op, operand1, operand2);
                operands.push(result);

                // Вывод шагового решения
                printStep("Operation: " + string(1, op), operands, operators);
            }

            operators.push(currentChar);  // Помещаем текущий оператор в стек операторов

            // Вывод шагового решения
            printStep("Operator Push: " + string(1, currentChar), operands, operators);
        }
    }

    // Выполняем оставшиеся операции
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        double operand2 = operands.top();
        operands.pop();

        double operand1 = operands.top();
        operands.pop();

        double result = performOperation(op, operand1, operand2);
        operands.push(result);

        // Вывод шагового решения
        printStep("Operation: " + string(1, op), operands, operators);
    }

    // Возвращаем результат
    if (!operands.empty())
        return operands.top();
    else {
        cerr << "Ошибка: неверное выражение." << endl;
        return 0.0;
    }
}

int main() {
    string expression = "-1*3+[5*(3-2)^2]^3/5";
    cout << "Выражение: " << expression << endl;

    double result = evaluateExpression(expression);

    cout << "Результат: " << result << endl;

    return 0;
}
