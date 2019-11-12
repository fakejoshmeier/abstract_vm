// Created: Oct. 25, 2019
// Modified: Oct. 25, 2019
// By: Josh Meier

#include "abstractVM.hpp"

/*
The creation of a temp file is a really good idea, tbh.  Makes a lot of sense
Don't need to write a second loop to handle the an array buffer or whatever, just
need to keep reading from either file
*/

int		error(std::string error, int flag) {
	if (flag == USAGE_ERROR)
		std::cout << USAGE_ERROR_STR << std::endl;
	else if (flag == READ_ERROR)
		std::cout << "avm: " << error << READ_ERROR_STR << std::endl;
	return (-1);
}

int		main(int ac, char **av) {
	std::string line;
	int			lineNumber = 0;

	if (ac > 2)
		return (error(NULL, USAGE_ERROR));
	if (ac == 1) { // Begin reading from stdin, as no file was provided
		std::ofstream file("tmp");  // Write to a tmp file, meaning that I read from a file either way and save on code
		while (std::cin.good()) {
			std::getline(std::cin, line); // Eyyy, GNL's triumphant return.
			if (line.compare(";;"))
				break ;
			file << line << std::endl;
		}
		file.close();
	}
	std::fstream file;
	file.open(ac == 1 ? "tmp" : av[1]);
	if (file.fail())
		return (error(av[1]), READ_ERROR);
	while (file.good()) {
		std::getline(file, line);
		++lineNumber;
		try {}
		catch () {

		}
	}
	file.close();
	remove("tmp");
	return (0);
}