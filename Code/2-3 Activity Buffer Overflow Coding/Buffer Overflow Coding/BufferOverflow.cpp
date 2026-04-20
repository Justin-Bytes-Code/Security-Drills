// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <string> //Added for the resizeability rather then using set sizes. 

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_number
  //  variable, and its position in the declaration. It must always be directly before the variable used for input.
  //  You must notify the user if they entered too much data.

  const std::string account_number = "CharlieBrown42";
  std::string user_input;

  const size_t MAX_INPUT = 20;


  std::cout << "Enter a value: ";
  std::cin >> user_input;

  //Checks if input is longerthen 20
  if (user_input.length() > MAX_INPUT)
  {
      std::cout << "\n\033[31mError: Too many characters entered. Maximum allowed is 20.\033[0m\n" << std::endl;
      user_input = user_input.substr(0, MAX_INPUT);
  }
  else {
      std::cout << "You entered: " << user_input << std::endl;
      std::cout << "Account Number = " << account_number << std::endl;
  }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
