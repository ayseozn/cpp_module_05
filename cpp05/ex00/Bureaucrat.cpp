#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150){}

Bureaucrat::Bureaucrat(std::string Name): name(Name), grade(150)
{}

Bureaucrat::Bureaucrat(std::string Name, int grade): name(Name)
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.getName())
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this == &other)
        return *this;
    this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const
{
    return(this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void    Bureaucrat::setGrade(int grade)
{
    if(grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
    else
        this->grade = grade;
}

void    Bureaucrat::increaseDegree()
{
    setGrade(this->grade - 1);
}

void    Bureaucrat::reduce_degree()
{
    setGrade(this->grade + 1);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& other)
{
    o << other.getName() << ", bureaucrat grade " << other.getGrade();
    return o;
}
