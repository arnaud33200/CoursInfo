package contact.entities;

import java.io.Serializable;

import javax.persistence.Basic;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlID;
import javax.xml.bind.annotation.XmlRootElement;


@Entity(name = "hellobean")
@XmlRootElement(name="hellobean")
@XmlAccessorType(XmlAccessType.FIELD)
public class HelloBean implements Serializable {
	
	private static final long serialVersionUID = 1L;

	@Basic
	@XmlElement
	private String helloMsg;
	
	@Id
	@XmlID
	@XmlElement
	private String clientName;
	
	//@XmlElement
	public String test;
	
	public HelloBean() {
		helloMsg = "Hello ";
		clientName = "nobody";
	}

	public String getHelloMsg() {
		return helloMsg;
	}

	public void setHelloMsg(String helloMsg) {
		this.helloMsg = helloMsg;
	}

	public String getClientName() {
		return clientName;
	}

	public void setClientName(String clientName) {
		this.clientName = clientName;
	}
}
