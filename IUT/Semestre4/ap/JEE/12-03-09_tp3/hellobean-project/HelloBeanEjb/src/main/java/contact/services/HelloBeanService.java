package contact.services;

import java.util.List;

import javax.ejb.Remote;

import contact.entities.HelloBean;


@Remote
public interface HelloBeanService {
	
	public String sayHello ();
	HelloBean add (HelloBean bean);
	HelloBean update (HelloBean bean);
	HelloBean get (String clientName);
	Boolean del (String clientName);
	List<HelloBean> getAll ();

}
