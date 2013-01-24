class MyOtherException extends Exception
{
    public MyOtherException()
    {
        super();
    }
    
    public MyOtherException(String s)
    {
        super(s);
    }
    
    public String toString()
    {
		return "exception de MyOtherException";
	}
}
