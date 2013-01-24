class MyException extends Exception
{
    public MyException()
    {
        super();
    }
    
    public MyException(String s)
    {
        super(s);
    }
    
    public String toString()
    {
		System.out.println("exception de MyException");
	}
}
