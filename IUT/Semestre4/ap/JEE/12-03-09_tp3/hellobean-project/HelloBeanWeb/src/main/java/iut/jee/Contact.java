package iut.jee;

import java.io.Serializable;
import java.util.Date;

//mvn eclipse:clean -Dwtpversion=2.0

public class Contact implements Serializable {
	
	private static final long serialVersionUID = 1L;
	
	private String name;
	private String email;
	private String phone;
	private Date birthday;
	
	
	public Contact() {
		name = "Nom";
		email = "contact@mail.m";
	}


	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public String getEmail() {
		return email;
	}


	public void setEmail(String email) {
		this.email = email;
	}


	public String getPhone() {
		return phone;
	}


	public void setPhone(String phone) {
		this.phone = phone;
	}


	public Date getBirthday() {
		return birthday;
	}


	public void setBirthday(Date birthday) {
		this.birthday = birthday;
	}

}
