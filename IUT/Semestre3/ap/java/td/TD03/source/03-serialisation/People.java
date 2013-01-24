// People.java
import java.io.Serializable;
import java.util.Calendar;
import java.util.Date;
public class People implements Serializable 
{
	private static final long serialVersionUID = 1L;
	private final String firstName;
	private final String name;
	private final Date birthday;
	
	public People(String firstName, String name, int year, int month, int day) 
	{
		this.firstName = firstName;
		this.name = name;
		Calendar cal = Calendar.getInstance();
		cal.set(year, month, day);
		this.birthday = cal.getTime();
	}
	
	public final String firstName()
	{ return firstName; }
	
	public final String name() { return name; }
	
	public final Date birthday() { return birthday; }
	
	public String toString()
	{
		return firstName + " " + name + " " + birthday.toString();
	}
}
