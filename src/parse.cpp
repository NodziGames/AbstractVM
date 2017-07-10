#include <AbstractVM.hpp>


int     syntax_check(std::string line)
{
    std::regex rgx_ints("^push( +)int(8|16|32)\\(-?[0-9]+\\)( *)"); //Checks for Push int 8 / 16 / 32
    std::regex rgx_decimals("^push( +)(float|double)\\(-?[0-9]+(.[0-9]+)?\\)( *)");
    std::regex rgx_modifications("^(pop|dump|add|mul|sub|div|mod|print|exit)( *)");
    std::regex rgx_assert("^assert( +)(int(8|16|32)|float|double)\\(-?[0-9]+(.[0-9]+)?\\)( *)");
    std::regex rgx_exit("( ?);;( *)");
    if (std::regex_match(line, rgx_ints) || std::regex_match(line, rgx_decimals) || std::regex_match(line, rgx_modifications) || std::regex_match(line, rgx_assert) || std::regex_match(line, rgx_exit))
        return (1);
    else
        return (0);
}

std::string remove_whitespace_front(std::string line)
{
    int i = 0;
    while (line[i] == ' ')
    {
        i++;
    }
    std::string newline = line.substr(i, line.length() - i);
    return newline;
}

std::string trim(std::string line)
{
    std::string newstr;
    int comment_start = 0;

    comment_start = line.find_first_of(";");
    newstr = line.substr(0, comment_start);
    return (newstr);
}

std::vector<std::string> parse(std::string filename, Exceptions & excep)
{
    std::vector<std::string> commands;
    bool found_error = false;
    int c_line = 1; //Current Line That It's Iterating Through

    std::ifstream inFile;
    inFile.open(filename);

    if (inFile)
    {
        std::string line;

        while (getline(inFile, line))
        {
            line = trim(line);
            line = remove_whitespace_front(line);
            if (line != "")
            {
                if (syntax_check(line))
                {
                    commands.push_back(line);
                }
                else
                {
                    std::cout << "Failed! Syntax Error At Line: " + std::to_string(c_line) << std::endl;
                    found_error = true;
                }
            }
            c_line++;
        }

        if (found_error == true)
        {
            commands.clear();
            commands.push_back("failed");
        }
        if (commands.size() == 0)
            excep.throwEmptyFile();
        return (commands);
    }
    else
        excep.throwInvalidFile();
    return (commands);
}