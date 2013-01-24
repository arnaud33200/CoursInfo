using System;
using System.Net;
using System.IO;
using System.Xml.Linq;
using System.Linq;
using System.Xml.Serialization;
using System.Collections;
using System.Collections.Generic;


namespace RESTClient
{
	
	[XmlRoot("hellobean")]
	public class HelloBean {
		
		[XmlElement(ElementName = "helloMsg")]
		public String helloMsg;
		
		[XmlElement(ElementName = "clientName")]
		public String clientName;
	}

	
	public class HelloBeanService {
		public HelloBean get (String clientname) {
			RESTClient<HelloBean> restClient = new RESTClient<HelloBean>();
			return restClient.@get("http://localhost:8080/ContactREST/rest/hello/Vincent");
		}	
		public HelloBean update (HelloBean changedBean) {
			RESTClient<HelloBean> restClient = new RESTClient<HelloBean>();
			return restClient.post("http://localhost:8080/ContactREST/rest/hello/", changedBean);
		}	
	}
	
	class MainClass
	{
		public static void Main (string[] args)
		{
			HelloBeanService srv = new HelloBeanService();
			HelloBean bean = srv.@get ("Vincent");
			Console.WriteLine (bean.helloMsg+bean.clientName);
			
			bean.clientName = "Thomas";
			HelloBean changedbean = srv.update (bean);
			Console.WriteLine (changedbean.helloMsg+changedbean.clientName);
		}
	}
}
