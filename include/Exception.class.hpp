#pragma once
#include <AbstractVM.hpp>

class Exceptions
{
    public:

        class StackTooSmall : public std::exception
        {
            virtual const char *what() const throw();
        } StackTooSmall;

        class NoExit : public std::exception
        {
            virtual const char *what() const throw();
        } NoExit;

        class AssertFail : public std::exception
        {
            virtual const char *what() const throw();
        } AssertFail;

        class PrintFail : public std::exception
        {
            virtual const char *what() const throw();
        } PrintFail;

        class InvalidFile : public std::exception
        {
            virtual const char *what() const throw();
        } InvalidFile;

        class EmptyFile : public std::exception
        {
            virtual const char *what() const throw();
        } EmptyFile;

        void    throwStackTooSmall();
        void    throwNoExit();
        void    throwAssertFail();
        void    throwPrintFail();
        void    throwInvalidFile();
        void    throwEmptyFile();
};