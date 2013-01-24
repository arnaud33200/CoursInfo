package iut.jee.rest;

import java.util.ArrayList;
import java.util.List;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;

import contact.entities.HelloBean;

@XmlRootElement(name="hellobeanlist")
@XmlAccessorType(XmlAccessType.FIELD)
public class ListHelloBean {
	
	@XmlElement
	private List<HelloBean> beans;
	
	public ListHelloBean() {
		beans = new ArrayList<HelloBean>();
	}

	public List<HelloBean> getBeans() {
		return beans;
	}

	public void setBeans(List<HelloBean> beans) {
		this.beans = beans;
	}
	
	public void add(HelloBean bean) {
		beans.add(bean);
	}
}