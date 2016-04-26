/**************************************************************
 * File:    MyException.h
 * Project: CMSC 341 - Project 4
 * Author : Dinara Sagitova
 * Date   : 4/22/16
 * Section: 
 * E-mail:  dsagit1@umbc.edu
 *
 * MyException class definition.
 *************************************************************/

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <string>

class MyException 
{
public:
    /*  Name: 			MyExceptions (Constructor)
     *  PreCondition: 	String containing error description.  
     *  PostCondition:  Error object
     */
    MyException(std::string message): m_message(message) {}

    /*  Name: 			GetMessage
     *  PreCondition: 	None.  
     *  PostCondition:  Returns error message.
     */
    const std::string getMessage() 
    { 
    	return m_message; 
    }
    
private:
    std::string m_message;
};

#endif