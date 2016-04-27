//
// Errors.hh for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Wed Apr 27 16:40:33 2016 Anaïs Foncel
// Last update Wed Apr 27 18:06:58 2016 Anaïs Foncel
//

#ifndef ERRORS_HH__
# define ERRORS_HH__

# include "string"

namespace		Errors
{
  class Exceptions : public std::exception
  {
  private:
    std::string _message;

  public:
    enum        Exceptions_Type
      {
        unknown = 0,
        FuncFail,
        max_exception
      };

    ~Exceptions() throw();
    explicit Exceptions(Exceptions_Type type, const std::string &mess = "");
    virtual const char  *what() const throw();
  };
};

#endif /* !ERRORS_HH__ */
