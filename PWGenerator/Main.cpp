#include <iostream>
#include <chrono>
#include <random>
#include <vector>

int main()
{
	int length;
	char excluded[16] = { '`', '(', ')', '-', '=', '+', '[', ']', 92, ';', ':', 39, '"', ',', '.', '/' }; //92 -> \, 39 -> '.

	int seed = (int)std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> randomNumber(33, 122); //33-122 are the decimal representation of ASCII letters, numbers, and characters to be generated (minus excluded).

	while (true)
	{
		std::cout << "Enter the length of your password (must be between 8 and 24): ";
		std::cin >> length;

		if (length < 8 || length > 24)
		{
			std::cout << "Please enter a number between 8 and 24." << std::endl;
			continue;
		}

		std::vector<char> password;
		password.reserve(length);

		for (int i = 0; i < length; i++)
		{
			password.push_back(randomNumber(generator));

			for (int x = 0; x < 16; x++) //16 is the excluded characters.
				while (password[i] == excluded[x]) //This loop reassigns an element if it is an excluded character.
				{
					password[i] = randomNumber(generator);
					x = 0; //x is set to 0 to make sure the loop didn't generate another exluded character.
				}
		}

		std::cout << "Your password is: ";

		for (int i = 0; i < length; i++)
			std::cout << password[i];

		std::cout << std::endl;
	}

	std::cin.get();
}