
package testmain;

import java.util.Hashtable;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

import contact.entities.HelloBean;
import contact.services.HelloBeanService;



public class TestMain {
	
	private Hashtable<String, String> ht=new Hashtable<String, String>();
	
	private String server_url;

	public TestMain() {
		server_url = "localhost";
		ht.put("java.naming.factory.initial", "org.jnp.interfaces.NamingContextFactory");
		ht.put("java.naming.factory.url.pkgs", "org.jboss.naming:org.jnp.interfaces");
		ht.put("java.naming.provider.url", server_url);
	}

	public HelloBeanService getHelloBeanService() {
		return getService("HelloBeanEAR/HelloBeanServiceImpl/remote");
	}
	
	
	@SuppressWarnings("unchecked")
	public <T> T getService(String remotePath)
	{
		Context context;
		T s = null;
		try {
			context = new InitialContext(ht);
			s = (T) context
			.lookup(remotePath);
		} catch (NamingException e) {
			e.printStackTrace();
		}
		return s;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		TestMain tm = new TestMain();
		System.out.println("TestRMIClient");
		HelloBeanService srv = tm.getHelloBeanService();
		HelloBean b = srv.get("Vincent");
		System.out.println(b.getHelloMsg()+b.getClientName());
		
	}

}