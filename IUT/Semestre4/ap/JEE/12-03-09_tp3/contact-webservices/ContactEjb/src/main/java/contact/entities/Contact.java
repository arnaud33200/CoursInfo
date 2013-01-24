package contact.entities;

import java.io.Serializable;

import javax.persistence.Basic;
import javax.persistence.Id;
import javax.persistence.Table;

import javax.persistence.Entity;

@Entity
@Table( name = "Contact" )
public class Contact implements Serializable {
	
	private static final long serialVersionUID = 1L;

	
	@Id
	private String name;
	
	
	@Basic 
	private String firstname;
	
	@Basic
	private int age;
	
	@Basic 
	private String phone;
	
	@Basic 
	private String email;
	
	
	public Contact() {
	}

	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}


	public String getFirstname() {
		return firstname;
	}


	public void setFirstname(String firstname) {
		this.firstname = firstname;
	}


	public int getAge() {
		return age;
	}


	public void setAge(int age) {
		this.age = age;
	}


	public String getPhone() {
		return phone;
	}


	public void setPhone(String phone) {
		this.phone = phone;
	}


	public String getEmail() {
		return email;
	}


	public void setEmail(String email) {
		this.email = email;
	}

	
}
