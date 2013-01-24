package iut.jee.soap;

import java.util.List;

import javax.ejb.EJB;
import javax.ejb.Stateless;
import javax.jws.WebMethod;
import javax.jws.WebParam;
import javax.jws.WebResult;
import javax.jws.WebService;

import contact.entities.HelloBean;
import contact.services.HelloBeanService;


/**
 * test-it : http://localhost:8080/jbossws/services
 * @author vrabeux
 *
 */
@WebService (name = "helloService")
@Stateless
public class HelloBeanServiceSOAP implements HelloBeanService {

	
	@EJB (mappedName = "ContactEAR/HelloBeanServiceImpl/remote")
	HelloBeanService deleg;
	

	@WebMethod
	public @WebResult(name = "hellobean") HelloBean add(@WebParam (name = "hellobean" ) HelloBean bean) {
		return deleg.add(bean);
	}

	@Override
	public @WebResult(name = "hellobean") HelloBean update(HelloBean bean) {
		return deleg.update(bean);
	}

	@Override
	@WebMethod
	public @WebResult(name = "hellobean") HelloBean get(@WebParam(name = "clientname") String clientName) {
		return deleg.get(clientName);
	}

	@Override
	public @WebResult(name = "boolean") Boolean del(String clientName) {
		return deleg.del(clientName);
	}

	@Override
	@WebMethod
	public @WebResult(name = "hellobeanlist") List<HelloBean> getAll() {
		return deleg.getAll();
	}


	@WebMethod
	public String sayHello() {
		return deleg.sayHello();
	}
}
