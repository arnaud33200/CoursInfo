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
		System.out.println("exception de MySubException");
	}
}
