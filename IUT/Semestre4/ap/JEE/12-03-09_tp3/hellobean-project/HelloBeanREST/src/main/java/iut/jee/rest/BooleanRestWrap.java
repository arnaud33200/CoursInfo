package iut.jee.rest;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement(name="boolean")
@XmlAccessorType(XmlAccessType.FIELD)
public class BooleanRestWrap {
	
	@XmlElement
	private boolean value;
	
	public BooleanRestWrap() {
	}
	
	public BooleanRestWrap(boolean value) {
		this.value = value;
	}

	public boolean isValue() {
		return value;
	}

	public void setValue(boolean value) {
		this.value = value;
	}

}
