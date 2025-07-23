#include <iostream>
#include <string>
#include <fstream>

std::string replacer(std::string line, std::string search, std::string replace)
{
    std::size_t found;

    found = line.find(search);
    while (found != std::string::npos)
    {
        line.erase(found, search.size());
        line.insert(found, replace);
        found = line.find(search, found);
    }
    return (line);
}

void open_file(char *filename, std::string search, std::string replace)
{
    std::string line;
    std::ofstream ofs;

    std::ifstream f(filename);
    if (!f)
    {
        std::cerr << "Error: file '" << filename << "' not found";
        return;
    }
    std::string newFile = std::string(filename) + ".replace";
    ofs.open(newFile.c_str());
    while (std::getline(f, line))
    {
        line = replacer(line, search, replace);
        ofs << line << "\n";
    }
    f.close();
    ofs.close();
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: <Filename> <Search> <Replace>";
        return (1);
    }
    std::string search = argv[2];
    if (search.empty())
    {
        std::cerr << "Error: 'Search' cannot be empty";
        return (2);
    }
    open_file(argv[1], argv[2], argv[3]);
}
