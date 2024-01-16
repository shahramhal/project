#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

// Function to generate a password
std::string gen_Password() {
  const std::string lowercase = "abcdefghijklmnopqrstuvwsvnz"; // all lowercases
  const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWSVYZ"; // all uppercases
  const std::string numbers = "0123456789"; // all numbers

  // Generate a random length for the password within a specified range
  int length = std::rand() % 6 + 10; // Modified for testing different password lengths

  std::string password;
  bool hasLowercase = false;
  bool hasUppercase = false;
  bool hasNumber = false;

  // Ensure the password has at least one lowercase character
  while (!hasLowercase) {
    char next = lowercase[std::rand() % lowercase.length()];
    password += next;
    hasLowercase = true;
  }

  // Ensure the password has at least one uppercase character
  while (!hasUppercase) {
    char next = uppercase[std::rand() % uppercase.length()];
    password += next;
    hasUppercase = true;
  }

  // Ensure the password has at least one number
  while (!hasNumber) {
    char next = numbers[std::rand() % numbers.length()];
    password += next;
    hasNumber = true;
  }

  // Fill the remaining password characters randomly
  for (int r = 3; r < length; ++r) {
    char next = lowercase[std::rand() % lowercase.length()];

    while ((r > 0 && next == password[r - 1]) ||
           (std::isupper(next) && std::isupper(password[r - 1]))) {
      next = lowercase[std::rand() % lowercase.length()];
    }

    password += next;
  }

  return password;
}


int main() {
  // Seed for random number generation
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  // Test the gen_Password function by printing 20 generated passwords
  for (int i = 1; i <= 20; ++i) {
    std::string password = gen_Password();
    std::cout << "Password " << i << ": " << password << std::endl;
    // Additional assertions or checks for black box testing can be added here
  
  if (password.length() <16)
    std::cout<<"This is not valid"<< std:: endl;
  else
    std::cout<<"This is valid"<<std::endl;
  }

  
  return 0;
}
