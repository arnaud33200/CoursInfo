
package iut.jee.clients.soapservices;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for get complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="get">
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;element name="clientname" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/restriction>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "get", propOrder = {
    "clientname"
})
public class Get {

    protected String clientname;

    /**
     * Gets the value of the clientname property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getClientname() {
        return clientname;
    }

    /**
     * Sets the value of the clientname property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setClientname(String value) {
        this.clientname = value;
    }

}
