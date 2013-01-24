package contact.services;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.ejb.Stateless;
import javax.jws.WebMethod;
import javax.jws.WebService;

import contact.entities.HelloBean;


/**
 * La base de donnee est simulee.
 * @author vrabeux
 *
 */
@Stateless
@WebService
public class HelloBeanServiceImpl implements HelloBeanService {

	Map<String, HelloBean> beans;
	
	public HelloBeanServiceImpl() {
		beans = new HashMap<String, HelloBean>();
		HelloBean b1 = new HelloBean();
		b1.setClientName("Vincent");
		beans.put("Vincent", b1);
		
		HelloBean b2 = new HelloBean();
		b2.setClientName("Florent");
		beans.put("Florent", b2);
	}
	
	@WebMethod
	public String sayHello () {
		return "Hello !";
	}
	
	@Override
	public HelloBean add(HelloBean bean) {
		// Ajout (ne marche pas car stateless)
		beans.put(bean.getClientName(), bean);
		return beans.get(bean.getClientName());
	}

	@Override
	public HelloBean update(HelloBean bean) {
		// Mise a jour
		beans.put(bean.getClientName(), bean);
		return beans.get(bean.getClientName());
	}

	@Override
	public HelloBean get(String clientName) {
		return beans.get(clientName);
	}

	@Override
	public Boolean del(String clientName) {
		HelloBean b = beans.remove(clientName);
		return b == null;
	}

	@Override
	public List<HelloBean> getAll() {
		List<HelloBean> l = new ArrayList<HelloBean>();
		l.addAll(beans.values());
		return l;
	}
}
