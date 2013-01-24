class MySubException extends MyException
{
    public MySubException()
    {
        super();
    }
    
    public MySubException(String s)
    {
        super(s);
    }
    
    public String toString()
    {
		return "exception de MySubException";
	}
}
