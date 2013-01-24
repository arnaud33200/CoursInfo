package iut.jee.rest;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.StringReader;
import java.util.List;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.servlet.http.HttpServletRequest;
import javax.ws.rs.Consumes;
import javax.ws.rs.DELETE;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.PUT;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Unmarshaller;

import org.codehaus.jettison.mapped.MappedNamespaceConvention;
import org.jboss.resteasy.annotations.providers.jaxb.json.Mapped;
import org.jboss.resteasy.annotations.providers.jaxb.json.XmlNsMap;
import org.jboss.resteasy.plugins.providers.jaxb.json.JettisonMappedMarshaller;
import org.jboss.resteasy.plugins.providers.jaxb.json.JettisonMappedUnmarshaller;

import contact.entities.HelloBean;
import contact.services.HelloBeanService;

@Path("/hello")
public class HelloWorldREST {

	public HelloBeanService getService() {
		Context context;
		HelloBeanService s = null;
		try {
			context = new InitialContext();
			s = (HelloBeanService) context.lookup("HelloBeanEAR/HelloBeanServiceImpl/remote");
		} catch (NamingException e) {
			e.printStackTrace();
		}
		return s;
	}

	HelloBeanService deleg;

	public HelloWorldREST() {
		deleg = getService();
	}

	@GET
	@Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
	@Mapped(namespaceMap = { @XmlNsMap(namespace = "http://www.w3.org/2001/XMLSchema-instance", jsonName = "instance") })
	public ListHelloBean get() {
		List<HelloBean> l = deleg.getAll();
		ListHelloBean lb = new ListHelloBean();
		for (HelloBean helloBean : l) {
			lb.add(helloBean);
		}
		return lb;
	}

	@GET
	@Path("/{clientname}")
	@Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
	@Mapped(namespaceMap = { @XmlNsMap(namespace = "http://www.w3.org/2001/XMLSchema-instance", jsonName = "instance") })
	public HelloBean get(@PathParam("clientname") String clientname) {
		return deleg.get(clientname);
	}

	/**
	 * test it : wget --header "Content-Type: application/json"
	 * --post-data='{"hellobean":{"helloMsg":"Hello ","clientName":"Titi"}}'
	 * http://localhost:8080/ContactREST/rest/hello or with curl : curl -i -X
	 * POST -d '{"hellobean":{"helloMsg":"Hello
	 * ","clientName":"Titi"}}' -H "Content-Type: application/json"
	 * http://localhost:8080/ContactREST/rest/hello
	 * 
	 * @param bean
	 * @return
	 */
	@POST
	@Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
	@Consumes({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
	@Mapped(namespaceMap = { @XmlNsMap(namespace = "http://www.w3.org/2001/XMLSchema-instance", jsonName = "instance") })
	public HelloBean update(final HelloBean bean) {
		return deleg.update(bean);
	}

	/**
	 * test it : curl -i -X PUT -d '{"hellobean":{"helloMsg":"Hello
	 * ","clientName":"Titi"}}' -H "Content-Type: application/json"
	 * http://localhost:8080/ContactREST/rest/hello
	 * 
	 * @param bean
	 * @return
	 * @throws JAXBException
	 * @throws IOException
	 */
	@PUT
	@Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
	@Consumes({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
	@Mapped(namespaceMap = { @XmlNsMap(namespace = "http://www.w3.org/2001/XMLSchema-instance", jsonName = "instance") })
	public HelloBean add(final HelloBean bean) {
		return deleg.add(bean);
	}

	/**
	 * test-it : curl -i -X DELETE -d '{"hellobean":{"helloMsg":"Hello
	 * ","clientName":"Titi"}}' -H "Content-Type: application/json"
	 * http://localhost:8080/ContactREST/rest/hello
	 * 
	 * @param bean
	 * @return
	 */
	@DELETE
	@Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
	@Consumes({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
	@Mapped(namespaceMap = { @XmlNsMap(namespace = "http://www.w3.org/2001/XMLSchema-instance", jsonName = "instance") })
	public BooleanRestWrap delete(final HelloBean bean) {
		return new BooleanRestWrap(deleg.del(bean.getClientName()));
	}

	@DELETE
	@Path("/{clientname}")
	@Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
	@Consumes({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
	@Mapped(namespaceMap = { @XmlNsMap(namespace = "http://www.w3.org/2001/XMLSchema-instance", jsonName = "instance") })
	public BooleanRestWrap deleteByClientName(
			@PathParam("clientname") String clientname) {
		// / Suppression en base
		return new BooleanRestWrap(deleg.del(clientname));
	}

}
