package com.example.exceptiontest;

public class NotExistStringException extends Exception
{
    public NotExistStringException(String msg)
    {
        super(msg);
    }
}
