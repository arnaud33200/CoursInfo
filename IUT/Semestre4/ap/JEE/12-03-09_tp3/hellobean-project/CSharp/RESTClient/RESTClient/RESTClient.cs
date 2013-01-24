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
	public class RESTClient<TType> {
		public TType get (String uri) {
			
			HttpWebRequest req = createRequest (uri, "GET");
            
			HttpWebResponse resp = (HttpWebResponse)req.GetResponse();
			Stream inStream = resp.GetResponseStream();
			
			XmlSerializer  s = new XmlSerializer (typeof(TType));
			TType bean  = (TType)s.Deserialize (inStream);
			inStream.Close ();
			return bean;
			
		}
		
		public TType post (String uri, TType elem) {
			
			HttpWebRequest req = createRequest (uri, "POST");
            
            XmlSerializer  s = new XmlSerializer (typeof(TType));
            Stream outStream = req.GetRequestStream();
            s.Serialize (outStream, elem);
            outStream.Close ();
   
			HttpWebResponse resp = (HttpWebResponse)req.GetResponse();
			Stream inStream = resp.GetResponseStream();
			
			TType bean  = (TType)s.Deserialize (inStream);
			inStream.Close ();
			return bean;
			
		}
		
		private HttpWebRequest createRequest (String uri, String method) {
			HttpWebRequest req = (HttpWebRequest)WebRequest.Create(uri);
			
			req.ContentType = "application/xml";
			req.Accept = "application/xml";
			req.Method = method;
			return req;
		}
	}
}

