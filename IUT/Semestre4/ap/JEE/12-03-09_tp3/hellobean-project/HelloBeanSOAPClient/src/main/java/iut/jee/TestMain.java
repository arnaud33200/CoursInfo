package iut.jee;

import iut.jee.clients.soapservices.HelloBean;
import iut.jee.clients.soapservices.HelloBeanServiceSOAPService;
import iut.jee.clients.soapservices.HelloService;

/**
 * mvn clean jaxws:wsimport
 * mvn clean compile
 * mvn assembly:single
 *	java -jar target/TestRMIClient-1.0.0-jar-with-dependencies.jar

 * @author zoolonly
 *
 */
public class TestMain {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		HelloBeanServiceSOAPService srv = new HelloBeanServiceSOAPService();
		HelloService hSrv = srv.getHelloServicePort();
		System.out.println(hSrv.sayHello());
		HelloBean bean = hSrv.get("Vincent");
		System.out.println(bean.getHelloMsg()+bean.getClientName());
		
	}

}
