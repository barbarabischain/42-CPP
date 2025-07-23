#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("Shrubbery Creation Form", SHRUB_SIGN, SHRUB_EXEC), _target(target){
    std::cout << "Shrubbery constructor called"  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), _target(other._target)
{
    std::cout << "Shrubbery Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    std::cout << "Shrubbery assignment operator called" << std::endl;
    if (this != &other)
        this->_target = other._target;
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
    std::cout << "Shrubbery Copy destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    if (!this->getSigned())
        throw(AForm::FormNotSignedException());
    else if (executor.getGrade() > SHRUB_EXEC)
        throw(AForm::GradeTooLowException());
    else
    {
        std::cout << BGREEN << "Creating Shrubbery..." << RESET << std::endl;
        std::ofstream shrubFile;
        std::string filename = this->_target + "_shrubbery";
        shrubFile.open(filename.c_str());
        shrubFile << "          &&& &&  & &&" << std::endl;
        shrubFile << "     && &\\/&\\|& ()|/ @, &&" << std::endl;
        shrubFile << "     &\\/(/&/&||/& /_/)_&/_&" << std::endl;
        shrubFile << "   &() &\\/&|()|/&\\/ '%" " & ()" << std::endl;
        shrubFile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
        shrubFile << " &&   && & &| &| /& & % ()& /&&" << std::endl;
        shrubFile << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
        shrubFile << "      &&&    \\|||" << std::endl;
        shrubFile << "              |||" << std::endl;
        shrubFile << "              |||" << std::endl;
        shrubFile << "              |||" << std::endl;
        shrubFile << "           __/|||\\__" << std::endl;
        shrubFile.close();
    }

}
