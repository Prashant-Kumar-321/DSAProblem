#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

// Approach1
namespace AdditionMulitiplication
{
  class Factorial
  {

  public:
    string calcualteFactorial(int n);
    string sum(string num1, string num2);
    string getLeadingZeroes(int cnt);

  private:
    void makeLengthEqual(string &num1, string &num2);
  };

  string Factorial::calcualteFactorial(int n)
  {
    string result = "1", prevSum = "1";

    for (int i = 1; i < n; ++i)
    {

      for (int j = 1; j <= i; ++j)
      {
        result = sum(result, prevSum);
      }
      prevSum = result;
    }

    return result;
  }

  string Factorial::getLeadingZeroes(int size)
  {
    string leadingZeroes("");
    while (size--)
    {
      leadingZeroes.push_back('0');
    }
    return leadingZeroes;
  }

  void Factorial::makeLengthEqual(string &num1, string &num2)
  {
    int lenDiff = std::abs((int)(num1.length() - num2.length()));
    string leadingZeroes = getLeadingZeroes(lenDiff);

    if (num1.length() > num2.length())
    {
      num2 = std::move(leadingZeroes + num2);
    }
    else
    {
      num1 = std::move(leadingZeroes + num1);
    }
  }

  string prepareAnsString(stack<int> &ans)
  {
    string result(ans.size(), '0');

    int idx = 0;
    while (!ans.empty())
    {
      result[idx++] = ans.top() + 48; // convert to respective char
      ans.pop();
    }

    return result;
  }

  string Factorial::sum(string num1, string num2) // "5321", "273"
  {
    makeLengthEqual(num1, num2);
    // "5321", "0273"

    // create stack and intialize
    stack<int> opr1, opr2, sumAns;
    for (int i = 0; i < num1.length(); ++i)
    {
      opr1.push(num1[i] - 48);
      opr2.push(num2[i] - 48);
    }
    // perform calcualtion
    int carry = 0, temp;
    while (!opr1.empty())
    {
      temp = opr1.top() + opr2.top() + carry;
      carry = temp / 10;
      sumAns.push(temp % 10); // unit digit of addition of  top digit

      opr1.pop();
      opr2.pop();
    }
    if (carry)
    {
      sumAns.push(carry);
    }

    return prepareAnsString(sumAns);
  }
}
using namespace AdditionMulitiplication;

// Approach2
// Using School Mulitiplication technique

class Factorial
{
public:
  vector<int> factorial(int n)
  {
    vector<int> prevMulti({1});

    for (int i = 2; i <= n; ++i)
    {
      multiply(i, prevMulti);
    }

    std::reverse(prevMulti.begin(), prevMulti.end());
    return prevMulti;
  }

  // multiply n with number whose digits are in vector 
  // n X number
  void multiply(int n, vector<int>& number)
  {
    int carry = 0;

    for (int i = 0; i < number.size(); ++i)
    {
      int temp = number[i] * n + carry;
      number[i] = temp % 10; // unit digit
      carry = temp / 10;     // remaining number
    }

    // push carry's digit into number
    while (carry)
    {
      number.push_back(carry % 10);
      carry /= 10;
    }
  }
};
