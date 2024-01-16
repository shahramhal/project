#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Function to generate a password
string gen_Password() {
  const string lowercase = "abcdefghijklmnopqrstuvwsvnz"; // all lowercases
  const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWSVYZ"; // all uppercases
  const string numbers = "0123456789"; // all numbers

  // Generate a random length for the password
  int length = rand() % 6 + 10;

  string password;
  bool hasUppercase = false;
  bool hasLowercase = false;
  bool hasNumber = false;

  // Randomly choose positions for each type of character
  int lowerPos = rand() % length;
  int numberPos = (lowerPos + rand() % (length - 1)) % length;
  int upperPos = (numberPos + rand() % (length - 2)) % length;

  // Fill the password with lowercase, number, and remaining uppercase characters
  for (int i = 0; i < length; ++i) {
    char next;

    if (i == lowerPos && !hasLowercase) {
      next = lowercase[rand() % lowercase.length()];
      hasLowercase = true;
    } else if (i != 0 && i == upperPos && !hasUppercase) {
      next = uppercase[rand() % uppercase.length()];
      hasUppercase = true;
      
    } else if (i == numberPos && !hasNumber) {
      next = numbers[rand() % numbers.length()];
      hasNumber = true;
    } else {
      do {
        next = lowercase[rand() % lowercase.length()];
      } while (i > 0 && next == password[i - 1]);
    }

    password += next;
  }

  return password;
}

// Function to check if a password is valid
bool isValidPassword(const string& password) {
    // Two consecutive characters must not be identical, irrespective of the case
    for (size_t i = 1; i < password.length(); ++i) {
      if (toupper(password[i]) == toupper(password[i - 1]))
        return false;
    
    // Check if the password contains at least one uppercase letter, one lowercase letter, and one digit
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasNumber = false;

    for (char ch : password) {
        if (isupper(ch)) {
            hasUppercase = true;
        } else if (islower(ch)) {
            hasLowercase = true;
        } else if (isdigit(ch)) {
            hasNumber = true;
        }
    }
    return hasUppercase && hasLowercase && hasNumber;

    }
  }

int main() {
  // Seed for random number generation
  srand(static_cast<unsigned int>(time(nullptr)));

  // Test the gen_Password function by printing 20 generated passwords
  for (int i = 1; i <= 20; ++i) {
    string password = gen_Password();
    cout << "Password " << i << ": " << password << endl;

    // Check if the password is valid
    if (isValidPassword(password)) {
      cout << "This is valid." << endl;
    } else {
      cout << "This is not valid." << endl;
    }
  }

  return 0;
}
